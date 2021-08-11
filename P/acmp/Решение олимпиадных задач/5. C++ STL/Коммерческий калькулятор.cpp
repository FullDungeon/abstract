/*
* ------------ КОММЕРЧЕСКИЙ КАЛЬКУЛЯТОР ------------
& структуры данных
~ prioity_queue
? нужно перебирать все пары чисел так, чтобы текущие два числа были самыми маленькми из имеющихся. Результат их суммы нужно добавлять в очередь с приоритетом, куда ранее добавили числа из исходных данных.

? нельзя использовать дек по причине того, что на стыке исходных данных и полученных результатов (в очереди с приоритетом) может нарушиться порядок неубывания.
? кроме того, можно не вычислять процент каждый раз, а найти его в самом конце.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

using T = double;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    priority_queue <int, vector <int>, greater_equal<int>> q;
    for (int i(0); i < n; i++) {
        int t;
        cin >> t;

        q.push(t);
    }

    // refr
    T sum(0);
    while (q.size() > 1) {
        T a = q.top(); q.pop();
        T b = q.top(); q.pop();

        sum += a + b;
        q.push(a + b);
    }

    cout << fixed << setprecision(2) << sum * 0.05;

    return 0;
}