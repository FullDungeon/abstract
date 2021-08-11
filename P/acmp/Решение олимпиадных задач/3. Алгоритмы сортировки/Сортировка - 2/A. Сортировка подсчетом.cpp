/*
* ------------ СОРТИРОВКА ПОДСЧЕТОМ ------------
& сортировка - 2
~ сортировка_подсчетом
? Сортировка подсчетом для неотрицательных чисел. Отрицательные числа на входе преобразую в положительные (__1__).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

void countingSort(line& d, int n, int k) {
    line c(k + 1);
    for (int i(0); i < n; i++)
        c[d[i]]++;
    
    int b = 0;
    for (int i(0); i < k+1; i++) {
        for (int j(0); j < c[i]; j++) {
            d[b++] = i;
        }
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    line d(n);
    for (auto& i : d) {
        cin >> i;
        i += 200; // % 1
    }

    countingSort(d, n, 400);

    for (auto& i : d)
        cout << i - 200 << " ";

    return 0;
}