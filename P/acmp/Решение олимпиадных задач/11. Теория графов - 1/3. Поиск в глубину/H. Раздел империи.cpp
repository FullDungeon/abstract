/*
* ------------ РАЗДЕЛ ИМПЕРИИ ------------
& поиск в глубину
~ dfs
? задача аналогичная задаче "Е. Компоненты связности", но с отличием, что тут нужно начинать обход с вершин "городов-столиц", перед этим примвоив всем им признак посещенности used[i] = true (__1__), ни в одной компоненте связности не окозалось больше одной такой вершины.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(a) a.begin(), a.end()

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, m;
matrix d;
line used;

int id;
map <int, line> comps;

void dfs(int curr) {
    used[curr] = true;
    comps[id].push_back(curr);

    for (auto next : d[curr]) {
        if (!used[next]) {
            dfs(next);
        }
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    d.resize(n);
    used.resize(n);
    for (int i(0); i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--, b--;

        d[a].push_back(b);
        d[b].push_back(a);
    }

    int k;
    cin >> k;
    line city;

    for (int i(0); i < k; i++) {
        int c;
        cin >> c;

        c--;

        used[c] = true; // % 1
        city.push_back(c);
    }

    for (auto c : city) {
        id++;
        dfs(c);
    }

    for (auto i : comps) {
        cout << i.second.size() << '\n';

        for (auto j : i.second) {
            cout << j + 1 << " ";
        }

        cout << '\n';
    }

    return 0;
}