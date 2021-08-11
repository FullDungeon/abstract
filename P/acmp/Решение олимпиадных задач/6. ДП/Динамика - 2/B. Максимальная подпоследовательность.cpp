/*
* ------------ Максимальная подпоследовательность ------------
& динамика - 2
~ одномерная_динамика
? Перебор. И простоя динамика.
todo: описать разбор
*/

// ошибка в условии во вложенном цикле + p[0] = 1, а не 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
 
using namespace std;
 
using line = vector <int>;
 
int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, mx(1);
    cin >> n;
 
    line d(n);
    for (auto& i : d)
        cin >> i;
 
    line p(n);
    for (int i(0); i < n; i++) {
        p[i] = 1;
 
        for (int j(0); j < i; j++) {
            if (d[j] < d[i] && p[j] + 1 > p[i]) {
                p[i] = p[j] + 1;
                mx = max(mx, p[i]);
            }
 
        }
    }
 
    cout << mx;
     
    return 0;
}