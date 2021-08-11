/*
* ------------ АЛГОРИТМ ФЛОЙДА - 2 ------------
& алгоритм флойда
~ флойд
? Просто алгоритм Флойда. Некоторых ребер нет, поэтому при поиске максимума нужно не забыть, что нельзя учитывать INF как возможный ответ mx.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int INF = 0x3f3f3f3f;

int n;

int main() {
    // ...
    cin >> n;

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

    int mx(0);
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            if (d[i][j] != INF)
                mx = max(mx, d[i][j]);
        }
    }

    cout << mx;

    return 0;
}