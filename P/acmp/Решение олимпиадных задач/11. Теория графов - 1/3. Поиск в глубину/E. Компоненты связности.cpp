/*
* ------------ КОМПОНЕНТЫ СВЯЗНОСТИ ------------
& поиск в глубину
~ dfs
? достаточно запустить серию обходов в глубину, запоминая, какие вершины были посещены в каком обходе 

warning: такую задачу можно также решить с помощью DSU
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

        --a, --b;

        d[a].push_back(b);
        d[b].push_back(a);
    }

    // refr
    for (int i(0); i < n; i++) {
        if (!used[i]) {
            id++;
            dfs(i);
        }
    }

    cout << comps.size() << '\n';
    for (auto i : comps) {
        cout << i.second.size() << '\n';

        for (auto j : i.second) {
            cout << j+1 << " ";
        }
        cout << '\n';
    }

    return 0;
}