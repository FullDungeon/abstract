/*
* ------------ ДРУЗЬЯ ------------
& поиск в глубину
~ dfs_проверка_на_ацикличность
? проверка ориентированного (возможно не связного) графа на ацикличность.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, m, sq;
matrix d;
line color;

const int WHITE = 0;
const int GRAY  = 1;
const int BLACK = 2;

bool dfs(int curr) {
    color[curr] = GRAY;

    for (auto next : d[curr]) {
        if (color[next] == WHITE) {
            dfs(next);
        }
        if (color[next] == color[curr]) {
            return true;
        }
    }

    color[curr] = BLACK;
    return false;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n >> m;

    d.resize(n);
    color.resize(n);
    for (int i(0); i < m; i++) {
        int a, b;
        cin >> a >> b;

        d[a - 1].push_back(b - 1);
    }

    for (int i(0); i < n; i++) {
        if (color[i] == WHITE) {
            if (dfs(i)) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";

    return 0;
}