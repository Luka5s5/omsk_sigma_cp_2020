#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

class SubTree {	
public:
	SubTree(unsigned int tl, unsigned int tr);
	std::pair<int,int> get(unsigned int L, unsigned int R);
	void upd(unsigned int L, unsigned int R, int k);
private:
	SubTree* l;
	SubTree* r;
	unsigned int tl;
	unsigned int tr;
	unsigned int tm;
	std::pair<int, int> min;
	int promise;
	void makeSons();
	void push();
	static std::pair<int,int> combine(std::pair<int,int>, std::pair<int,int>);
};
 
void SubTree::makeSons() {
	if (!l)
		l = new SubTree(tl, tm);
	if (!r)
		r = new SubTree(tm + 1, tr);
}
 
SubTree::SubTree(unsigned int tl, unsigned int tr): tl(tl), tr(tr), tm((tl + tr)/2), promise(0) {
	l = r = nullptr;
	min = {0, tr + 1 - tl};
}
 
std::pair<int,int> SubTree::get(unsigned int L, unsigned int R) {
	if (L > R)
		return {1e9, 0};
	if (tl == L && tr == R)
		return min;
	makeSons();
	push();
	return combine(l->get(L, std::min(tm, R)), r->get(std::max(tm + 1, L), R));
}
 
void SubTree::upd(unsigned int L, unsigned int R, int k) {
	if (L > R)
		return;
	if (tl == L && tr == R){
		min.first += k;
		promise += k;
		return;
	}
	makeSons();
	push();
	l->upd(L, std::min(tm, R), k);
	r->upd(std::max(tm + 1, L), R, k);
	min = combine(l->min, r->min);
}

void SubTree::push() {
	l->min.first += promise;
	r->min.first += promise;
	l->promise += promise;
	r->promise += promise;
	promise = 0;
}

std::pair<int,int> SubTree::combine(std::pair<int,int> L, std::pair<int,int> R) {
	if (L.first < R.first)
		return L;
	R.second += L.second * (L.first == R.first);
	return R;
}

long long solve(int n, std::vector<std::tuple<int,int,int,int>> v) {
	std::vector<std::tuple<int,int,int,int>> events(2 * n);
	const int SDV = 1e9;
	for (int i = 0; i < n; i++) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		std::tie(x1, y1, x2, y2) = v[i];
		events[i * 2] = std::make_tuple(x1, y1 + SDV, y2 + SDV, 1);
		events[i * 2 + 1] = std::make_tuple(x2, y1 + SDV, y2 + SDV, -1);
	}
	std::sort(events.begin(), events.end());
	int INF = 2 * 1e9 + 1;
	int last = INF;
	SubTree tree(0, 2 * 1e9);
	long long ans = 0; 
	for (auto t : events) {
		int x = 0, y1 = 0, y2 = 0, k = 0;
		std::tie(x, y1, y2, k) = t;
		if(last != INF){
			auto got = tree.get(0, 2*1e9);
			ans += 1ll * (x - last) * (INF - got.second * (got.first == 0));
		}
		tree.upd(y1 + 1, y2, k);
		last = x;
	}
	return ans;
}

main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<std::tuple<int,int,int,int>> v(n);
	for (int i = 0; i < n; ++i) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;
		v[i] = std::make_tuple(x1, y1, x2, y2);
	}
	std::cout << solve(n, v);
}
 
