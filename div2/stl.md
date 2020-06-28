# STL (Стандартная библиотека шаблонов)

## Vector

Vector - динамический массив.

<center><img src="vectormeme.jpg"></center>

Объявляется вектор так: `vector<тип, например int> имя_вектора(размер_вектора, чем_заполнить)`
### Основные методы

#### На метод можно нажать чтобы почитать более подробно.

[`vector.front()`](https://en.cppreference.com/w/cpp/container/vector/front) - возвращает первый элемент массива.

[`vector.back()`](https://en.cppreference.com/w/cpp/container/vector/back) - возвращает последний элемент массива.

[`vector.begin()`](https://en.cppreference.com/w/cpp/container/vector/begin) - указатель на первый элемент массива.

[`vector.end()`](https://en.cppreference.com/w/cpp/container/vector/end) - указатель на фикитвный элемент за последним.

[`vector.rbegin()`](https://en.cppreference.com/w/cpp/container/vector/rbegin) - указатель на последний элемент массива.

[`vector.rend()`](https://en.cppreference.com/w/cpp/container/vector/rend) - указатель на первый элемент массива.

![Картинка чтобы понятнее было](vectorendbegin.gif)

[`vector.push_back()`](https://en.cppreference.com/w/cpp/container/vector/push_back) - добавляет в конец массива то, что в скобочках, при необходимости увеличивает размер массива.

[`vector.pop_back()`](https://en.cppreference.com/w/cpp/container/vector/pop_back) - удаляет последний элемент массива, уменьшает размер на 1, **не возвращает удаленное значение**.

[`vector.resize()`](https://en.cppreference.com/w/cpp/container/vector/resize) - меняет размер массива, можно передать второй параметр, тогда все новые элементы инициализируются этими значениями.

## Pair

Pair - пара значений любых типов. Любых. Типов.

<center><img src="pairmeme.jpg"></center>
<center>(Это скомпилится)</center>

Чтобы обратиться к первому элементу пары надо писать `p.first`, ко второму - `p.second`. Пару можно инициализировать вот так `pair<int,string> p={2,"sigma"}`, или так `pair<int,string> p=make_pair(2,"sigma")`. Второй способ иногда не работает, рекомендуется пользоваться первым. <!--Вроде бы, я не уверен. --> Часто хочется нагромоздить кучу пар, если про у объекта более 2-х свойств(например точки в трехмерном пространстве). В таких случаях правильнее пользоваться собственноручно созданной структурой, или `tuple`-ом (про него подробнее написано ниже).

```c++
struct p{
    int x,y,z;
    p(){};
    p(int _x, int _y, int _z){
        x=_x;
        y=_y;
        z=_z;
    }
}

// или

// здесь должен быть пример с tuple-ом

```



___

## [Sigma Omsk](https://vk.com/sigma_omsk) 2020

