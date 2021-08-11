/*
* ------------ ЗВЕЗДА ------------
& поиск в ширину
~ dfs_планарный_граф
? поиск компонент связности на планарном графе через dfs
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int FREE = 0;
const int USED = 1;

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
    int n, m;
    cin >> n >> m;

    d.resize(n + 2, line(m + 2, USED));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            char c;
            cin >> c;

            d[i][j] = (c == '*' ? FREE : USED);
        }
    }

    int amount(0);
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