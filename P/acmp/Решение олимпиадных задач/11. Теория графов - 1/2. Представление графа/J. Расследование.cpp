/*
* ------------ ТУРНИР ------------
& представление графа
~ dfs ~ dfs_с_расстояниями_от_начальной_вершины
? при чтении запоминаем предков каждой вершины в массиве parent. С помощью dfs запишем в used "глубину" графа, т.е. определим для каждой вершины, как далеко она находистя от начальной (нулевой). Затем с помощью обычного цикла будем "поднимать вверх", к нулевой, вершины a и b (__1__).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

line used, parent;
matrix d;

void dfs(int curr, int deep) {
    used[curr] = deep;

    for (auto next : d[curr]) {
        if (!used[next]) {
            dfs(next, deep + 1);
        }
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;

    a--, b--;

    d.resize(n);
    used.resize(n);
    parent.resize(n);
    for (int j(1); j < n; j++) {
        int i;
        cin >> i;

        d[i - 1].push_back(j);
        parent[j] = i - 1;
    }

    dfs(0, 0);

    // % 1
    while (a != b) {
        int& v = (used[a] > used[b] ? a : b);

        v = parent[v];
    }

    cout << a + 1;

    return 0;
}