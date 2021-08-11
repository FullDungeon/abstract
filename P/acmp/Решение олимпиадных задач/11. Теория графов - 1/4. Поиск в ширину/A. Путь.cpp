/*
* ------------ ДРУЗЬЯ ------------
& поиск в ширину
~ bfs_кратчайшее_расстояние
? обычный поиск в ширину с нахождением расстояния
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n, s, e;
matrix d;
line dist, used;

const int INF = 0x3f3f3f3f;

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n;

    d.resize(n);
    used.resize(n);
    dist.resize(n, INF);
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            int v;
            cin >> v;

            if (v)
                d[i].push_back(j);
        }
    }

    cin >> s >> e;
    s--, e--;

    // решение
    queue <int> q;

    dist[s] = 0;
    used[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (auto next : d[curr]) {
            if (used[next]) continue;

            used[next] = true;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }

    cout << (dist[e] == INF ? -1 : dist[e]);

    return 0;
}