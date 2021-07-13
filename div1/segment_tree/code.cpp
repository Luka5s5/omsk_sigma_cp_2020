#include <iostream>
#include <vector>

const int N = 1e5;
int t[4 * N];
int push[4 * N];
std::vector<int> arr;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void psh(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    t[v * 2] += (tm - tl + 1) * push[v];
    t[v * 2 + 1] += (tr - tm) * push[v];
    push[v * 2] += push[v];
    push[v * 2 + 1] += push[v];
    push[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[v] += (r - l + 1);
        push[v]++;
        return;
    }
    int tm = (tl + tr) / 2;
    psh(v, tl, tr);   
    upd(v * 2, tl, tm, l, std::min(r, tm));
    upd(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int getSum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    psh(v, tl, tr);
    return getSum(v * 2, tl, tm, l, std::min(r, tm)) + getSum(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r);
}

int main() {
    int size = 5;
    arr = {1, 2, 3, 4, 5};
    build(1, 0, size - 1);
    std::cout << getSum(1, 0, size - 1, 0, 2) << std::endl;
    std::cout << getSum(1, 0, size - 1, 1, 4) << std::endl;
    upd(1, 0, size - 1, 2, 3);
    std::cout << getSum(1, 0, size - 1, 0, 2) << std::endl;
    std::cout << getSum(1, 0, size - 1, 1, 4) << std::endl;
}
