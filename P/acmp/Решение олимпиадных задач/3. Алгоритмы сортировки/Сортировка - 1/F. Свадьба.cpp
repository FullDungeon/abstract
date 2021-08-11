/*
* ------------ СВАДЬБА ------------
& сортировка - 1
? Ничего сложного. Просто сортировка и один цикл: замуж можно идти с тем, чье богатство больше текущего богатства Горогны.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using T      = double;
using line   = vector <T>;
using matrix = vector <line>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    T g;
    int n;
    cin >> n;

    line d(n);
    for (auto& i : d)
        cin >> i;

    cin >> g;

    sort(d.begin(), d.end(), [](int a, int b) {return a < b; });

    for (int i(0); i < n; i++) {
        if (g < d[i])
            g = (g + d[i]) / 2;
    }

    cout << fixed << setprecision(6) << g;

    return 0;
}