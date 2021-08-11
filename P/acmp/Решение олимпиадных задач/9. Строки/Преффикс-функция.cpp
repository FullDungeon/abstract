/*
* ------------ Преффикс-функция ------------
& алгоритмы на строках
~ преффикс_функция
? Вывод преффикс-функции строки.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <vector>

using namespace std;

using line = vector <int>;

line preffix(string s) {
    int n = s.size();
    line pi(n);

    int i(1), j(0);
    while (i < n) {
        if (s[i] == s[j]) {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0) {
            pi[i] = 0;
            i++;
        }
        else {
            j = pi[j - 1];
           // i++;
        }
    }

    return pi;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    for (auto i : preffix(s))
        cout << i << " ";

    return 0;
}