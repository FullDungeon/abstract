/*
* ------------ САМЫЙ ДЛИННЫЙ ПУТЬ ------------
& алгоритм флойд
~ флойд
? Просто алгоритм Флойда и больше ничего  
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
            mx = max(mx, d[i][j]);
        }
    }

    cout << mx;

    return 0;
}