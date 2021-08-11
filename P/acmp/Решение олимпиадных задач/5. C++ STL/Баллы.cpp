/*
* ------------ КОНДИЦИОНЕРЫ ------------
& библиотеки алгоритмов
~ STL ~ binarysearch
? бинарный поиск в уже отсортированном массиве и все
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define all(s) s.begin(), s.end()

using namespace std;

using line = vector <long long>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    line d;
    for (int i(0); i < n; i++) {
        long long p;
        cin >> p;

        d.push_back(p);
    }

    for (int i(0); i < k; i++) {
        long long p;
        cin >> p;

        cout << (binary_search(all(d), p) ? "YES " : "NO ");
    }

    return 0;
}
