/*
* ------------ ТРАНЗИТИВНОЕ ЗАМЫКАНИЕ ------------
& алгоритм флойда
~ флойд_транзитивное_замыкание
? Построение транзитивного замыкания.
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
    int n;
    cin >> n;

    matrix d(n, line(n)), w;
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cin >> d[i][j];
        }
    }

    w = d;
    
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
            }
        }
    }

    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}