/*
* ------------ Количество путей в лабиринте ------------
& динамика - 5
~ двумерная_динамика
? Нужно перебрать k раз весь массив d и попытаться сделать шаг в каждую клетку d[i][j]. КОгда это возможно? На четном шаге k можно попатсть только в такие клетки d[i][j], сумма i и j которых четное число, аналогично с нечетными. Кроме того, нельзя сделать шаг в клетку, которая "запрещена". Кол-во способов попасть в клетку равно сумме количеств попасть в соседние с ней клетки. Важно учесть, что если на k-м шаге d[n][n] не была посещена, то ответ равен 0, т.е. за k шагов невозможно попасть в d[n][n].

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

int n, m;
matrix d;

const int FREE = 0;
const int USED = -1;

line moI{ +1, -1,  0,  0 };
line moJ{  0,  0, +1, -1 };

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n >> m;

    d.resize(n + 2, line(n + 2, USED));
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= n; j++) {
            char c; 
            cin >> c;

            d[i][j] = (c == '1' ? USED : FREE);
        }
    }

    // refr
    bool is = false;
    d[1][1] = 1;

    for (int k(1); k <= m; k++) {
        int p = k % 2;

        for (int i(1); i <= n; i++) {
            for (int j(1); j <= n; j++) {
                if ((i + j) % 2 == p && d[i][j] != USED) {
                    d[i][j] = 0;

                    for (int t(0); t < 4; t++) {
                        int ni = i + moI[t];
                        int nj = j + moJ[t];

                        if (d[ni][nj] != USED)
                            d[i][j] += d[ni][nj];
                    }

                    if (i == n && j == n && k == m)
                        is = true;
                }
            }
        }
    }

    if (is)
        cout << d[n][n];
    else
        cout << 0;

    return 0;
}