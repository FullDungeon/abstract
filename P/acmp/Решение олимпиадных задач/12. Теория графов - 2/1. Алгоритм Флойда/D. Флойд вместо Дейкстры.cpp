/*
* ------------ ФЛОЙД ВМЕСТО ДЕЙКСТРЫ ------------
& алгоритм флойда
~ флойд
? Просто алгоритм Флойда.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int INF = 0x3f3f3f3f;


int main() {
    // ...
    int n, s, e;
    cin >> n >> s >> e;

    s--, e--;

    matrix d(n, line(n));
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cin >> d[i][j];

            if (d[i][j] == -1)
                d[i][j] = INF;
        }
    }
    
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    if (d[s][e] == INF)
        cout << -1;
    else
        cout << d[s][e];

    return 0;
}