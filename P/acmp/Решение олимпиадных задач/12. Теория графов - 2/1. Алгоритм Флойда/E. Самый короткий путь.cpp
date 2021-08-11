/*
* ------------ АЛГОРИТМ ФЛОЙДА ------------
& алгоритм флойда
~ флойд_проверка_на_наличие_отрицательного_цикла
? Нужно выполнить алгоритм Флойда для проверки на отрицательные циклы. Если такие есть, то вывести -1. Иначе вывести овтет - минимум. 
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

    matrix d(n, line(n));
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cin >> d[i][j];
        }
    }
    
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF ) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // ограничение снизу
                }
            }
        }
    }

    int mn(INF);
    for (int i(0); i < n; i++) {
        // проверка на наличие циклов
        if (d[i][i] < 0) {
            cout << -1;
            return 0;
        }
        
        for (int j(0); j < n; j++) {
            if (i != j)
                mn = min(mn, d[i][j]);
        }
    }

    cout << mn;

    return 0;
}