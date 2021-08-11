#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
using type = int;
using line = vector <type>;
using matrix = vector <line>;
 
struct point {
    int i, j;
};
 
const type FILL  = 1;
const type WHOLE = 0;
 
int n, m;
int sq, am;
point mn, mx;
matrix d, c, e;
 
vector <int> moI{ 0, 1,  0, -1 };
vector <int> moJ{ 1, 0, -1,  0 };
 
bool IsCorrect(int i, int j) {
    return i >= mn.i - 1 && j >= mn.j - 1 && i <= mx.i + 1 && j <= mx.j + 1;
}
 
void Copy(int i, int j) {
    c[i][j] = d[i][j];
    d[i][j] = WHOLE;
 
    sq++;
     
    mn.i = min(i, mn.i);
    mn.j = min(j, mn.j);
    mx.i = max(i, mx.i);
    mx.j = max(j, mx.j);
 
    for (int k(0); k < 4; k++) {
        int ni = i + moI[k];
        int nj = j + moJ[k];
 
        if (d[ni][nj] == FILL && c[ni][nj] == WHOLE)
            Copy(ni, nj);
    }
}
 
void Paint(int i, int j) {
    c[i][j] = FILL;
 
    for (int k(0); k < 4; k++) {
        int ni = i + moI[k];
        int nj = j + moJ[k];
 
        if (IsCorrect(ni, nj) && c[ni][nj] == WHOLE)
            Paint(ni, nj);
    }
}
 
void Analys(point mn, point mx) {
    for (int i(mn.i-1); i <= mx.i; i++) {
        for (int j(mn.j-1); j <= mx.j; j++) {
            if (c[i][j] == WHOLE) {
                am++;
                Paint(i, j);
            }
        }
    }
 
    am--;
}
 
void Input() {
    cin >> m >> n;
 
    d.resize(n + 2, line(m + 2, WHOLE));
    c.resize(n + 2, line(m + 2, WHOLE));
    e.resize(n + 2, line(m + 2, WHOLE));
 
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            char c;
            cin >> c;
 
            if (c == '.') d[i][j] = WHOLE;
            else d[i][j] = FILL;
        }
    }
}
 
void Solve() {
    Input();
 
    int square(0), amount(0); // общие
 
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (d[i][j] == FILL) {
                am = 0;
                sq = 0;
 
                mn.i = i; mn.j = j;
                mx.i = i; mx.j = j;
 
                Copy(i, j);
                Analys(mn, mx);
 
                c = e;
 
                if (amount < am) {
                    square = sq;
                    amount = am;
                }
                else if (amount == am) {
                    square = min(square, sq);
                }
            }
        }
    }
 
    cout << square;
}
 
int main() {
    // ...
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
     
    Solve();
 
    return 0;
}