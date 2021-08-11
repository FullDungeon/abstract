/*
* ------------ ОДИН КОНЬ ------------
& поиск в ширину
~ bfs_кратчайшее_расстояние_на_планарном_графе
? вычисление кратчайшего расстояния на планарном графе алгоритмом Ли
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n;
int ib, jb, ie, je;
matrix d;

const int FREE = 0;
const int USED = 1;

line moI{ -2, -2, -1, +1, +2, +2, +1, -1 };
line moJ{ -1, +1, +2, +2, +1, -1, -2, -2 };

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n;

    cin >> jb >> ib;
    cin >> je >> ie;

    ib++, jb++;
    ie++, je++;

    d.resize(n + 4, line(n + 4, USED));
    for (int i(2); i <= n + 1; i++) {
        for (int j(2); j <= n + 1; j++) {
            d[i][j] = FREE;
        }
    }

    // решение
    queue <pair <int, int>> q;
    q.push({ ib, jb });

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        if (i == ie && j == je) 
            break;
        
        for (int k(0); k < moI.size(); k++) {
            int ni = i + moI[k];
            int nj = j + moJ[k];

            if (d[ni][nj] == FREE) {
                q.push({ ni, nj });
                d[ni][nj] = d[i][j] + 1;
            }
        }
    }

    cout << d[ie][je];

    return 0;
}