/*
* ------------ ПОКРАСКА ЛАБИРИНТА ------------
& поиск в глубину
~ dfs_планарный_граф
? здесь нужно делать dfs из правого нижнего и левого верхнего углов. Суть проста: если dfs натыкается на стену, увеличиваем счетчик sq на единицу. В конце нужно вывести sq - 4, потому что у входов нет стен, и умножить на площадь одной стены, т.е. на 25.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, m, sq;
matrix d;

const int FREE = 0;
const int USED = 1;
const int WALL = 2;

void dfs(int i, int j) {
    if (d[i][j] != FREE) {
        sq += (d[i][j] == WALL);

        return;
    }

    d[i][j] = USED;

    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n;

    d.resize(n + 2, line(n + 2, WALL));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= n; j++) {
            char c;
            cin >> c;

            d[i][j] = (c == '.' ? FREE : WALL);
        }
    }

    dfs(1, 1);
    dfs(n, n);

    cout << (sq - 4) * 25;

    return 0;
}