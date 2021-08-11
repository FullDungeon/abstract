/*
* ------------ СТОЛОВАЯ ------------
& алгоритм флойда
~ флойд
? Просто алгоритм Флойда и поиск в матрице кратчайших путей d номера строки, в котором максимальное значение минимально из всех строк (и номер строки должен быть наименьшим).
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
    int n, m;
    cin >> n >> m;

    matrix d(n, line(n, INF));
    for (int t(0); t < m; t++) {
        int i, j, w;
        cin >> i >> j >> w;

        i--, j--;

        d[i][j] = w;
        d[j][i] = w;
    }

    // нули на диагоналях
    for (int i(0); i < n; i++)
        d[i][i] = 0;
    
    // Флойд
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {             
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int mn(0x3f3f3f3f), t(0);
    for (int i(0); i < n; i++) {
        int temp(0);

        for (int j(0); j < n; j++) {
            temp = max(temp, d[i][j]);
        }

        if (mn > temp) {
            mn = temp;
            t = i;
        }
    }

    cout << t + 1;

    return 0;
}