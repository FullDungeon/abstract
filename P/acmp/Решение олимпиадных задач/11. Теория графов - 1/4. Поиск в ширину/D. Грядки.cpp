/*
* ------------ ДРУЗЬЯ ------------
& поиск в ширину
~ dfs_планарный_граф
? нахождение компонент связности на планарнои графе
*/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const int FREE = 0;
const int USED = 1;

using line = vector <int>;
using matrix = vector <line>;

matrix d;

void dfs(int i, int j) {
    if (d[i][j] == USED)
        return;

    d[i][j] = USED;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, m, amount(0);
    cin >> n >> m;

    d.resize(n + 2, line(m + 2, USED));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            char c;
            cin >> c;

            if (c == '#') d[i][j] = FREE;
        }
    }

    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (d[i][j] == FREE) {
                amount++;
                dfs(i, j);
            }
        }
    }

    cout << amount;

    return 0;
}