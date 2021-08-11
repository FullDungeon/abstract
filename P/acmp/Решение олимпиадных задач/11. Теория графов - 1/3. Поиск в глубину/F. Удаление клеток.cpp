/*
* ------------ УДАЛЕНИЕ КЛЕТОК ------------
& поиск в глубину
~ dfs_планарный_граф
? подсчет кол-ва компонент связности с помощью dfs
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, m;
matrix d;

const int FREE = 0;
const int USED = 1;

void dfs(int i, int j) {
    if (d[i][j] != FREE)
        return;
    
    d[i][j] = 1;

    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    d.resize(n + 2, line(m + 2, USED));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            char c;
            cin >> c;

            d[i][j] = (c == '#' ? FREE : USED);
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