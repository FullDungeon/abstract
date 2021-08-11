/*
* ------------ УКЛАДКА ПЛИТКИ ------------
& поиск в глубину
~ dfs_планарный_граф
? подсчет кол-ва компонент связности с помощью dfs на планарном графе, но с единственным отличием. Вместо атрибута непосещенности вершины FREE используются два цвета WHITE и BLACK. Кроме того, условие возможности перехода на соседнюю клетку осложнено тем, что эти две соседние клетки должны быть различных цветов.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, m;
matrix d;

const int WHITE = 0;
const int BLACK = 1;
const int USED  = 3;

void dfs(int i, int j, int prev) {
    if (d[i][j] == USED || d[i][j] == prev)
        return;
    
    int temp = d[i][j]; // запоминаем текущий цвет
    d[i][j] = USED;

    dfs(i + 1, j, temp);
    dfs(i, j + 1, temp);
    dfs(i - 1, j, temp);
    dfs(i, j - 1, temp);
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    n = m = 8;
    
    d.resize(n + 2, line(m + 2, USED));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            char c;
            cin >> c;

            d[i][j] = (c == 'W' ? WHITE : BLACK);
        }
    }

    int amount(0);
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (d[i][j] != USED) {
                amount++;
                dfs(i, j, -1);
            }
        }
    }

    cout << amount;

    return 0;
}