/*
* ------------ ПЛОЩАДЬ МНОГОУГОЛЬНИКА ------------
& меньшиков
~ вычислительная_геометрия ~ площадь_простого_многоугольника
? Дан произвольный многоугольник без самопересечений и спорикосновений сторон. Нужно найти его площадь, зная координаты точек.
? Все просто: сначала считываем все точки и соединяем последнюю точку с первой (__1__). Затем по любой из формул нахождения площади простого многоугольника найти ее. Вывести на экран с одним знаком после запятой.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;

    Point() {
        cin >> x >> y;
    }
};

double SimplePolygonArea(vector <Point> d) {
    double area(0);

    for (int i(1); i < d.size(); i++) 
        area += (d[i].x - d[i - 1].x) * (d[i].y + d[i - 1].y);
    
    return abs(area /2);
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector <Point> d(n);
    d.push_back(d.front()); // % 1

    cout << fixed << setprecision(1) << SimplePolygonArea(d);

    return 0;
}