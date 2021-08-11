/*
* ------------ СУЩЕСТВОВАНИЕ ПУТИ ------------
& алгоритм флойда
~ флойд_проверка_на_наличие_цикла ~ флойд_поиск_вершин_на_отрицательных_циклах
? Итак, считываем матрицу (если ребра нет, т.е. прочитали 0, то ставим туда бесконечность INF - так нужно для Флойда). Запускаем флойда для поиска отрицательного цикла. Далее необходимо произвести проверку каждой вершины на принадлежность к отрицательному циклу (__1__) и просто вывести ответ.
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

    matrix d(n, line(n, INF));
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cin >> d[i][j];

            if (!d[i][j])
                d[i][j] = INF;
        }
    }
    
    // Флойд
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {             
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    // % 1: поиск вершин на отрицательных циклах
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF && d[k][k] < 0)
                    d[i][j] = -INF;
            }
        }
    }

    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            int ans;

            if      (d[i][j] == -INF) ans = 2; // путь сколь угодно маленького веса
            else if (i == j)          ans = 1; // кратчайший путь существует
            else if (d[i][j] == INF)  ans = 0; // пути нет
            else                      ans = 1; // кратчайший путь существует

            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}