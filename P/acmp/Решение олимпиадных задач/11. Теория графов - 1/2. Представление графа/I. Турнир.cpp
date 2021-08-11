/*
* ------------ ТУРНИР ------------
& представление графа
? нужно учесть то, что в графе не должно быть петель и чтобы между любыми двумя парами вершин было ровно ОДНО ребро. Ни больше, ни меньше. Сначала (важно!) считаем граф в матрицу смежности. Затем проверим каждую пару (i, j) такую, что 0 <= i, j < n. Если i == j, то там не должно быть ребер вообще, иначе должно быть только одно ребро.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <map>
#include <set>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    matrix d(n, line(n));
    for (int k(0); k < m; k++) {
        int i, j;
        cin >> i >> j;

        --i, --j;
        d[i][j]++;
    }

    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            if (d[i][j] + d[j][i] + (i == j) != 1) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}