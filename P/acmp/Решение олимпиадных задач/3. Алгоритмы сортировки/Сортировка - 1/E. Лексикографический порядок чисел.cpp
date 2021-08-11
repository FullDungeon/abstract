/*
* ------------ ЛЕКСИКОГРАФИЧЕСКИЙ ПОРЯДОК ЧИСЕЛ ------------
& сортировка - 1
~ STL ~ stringstream ~ distance
? Поместил все стрроки в set (строки получил переводом с помощью строковых потоков) и нашел позицю с помощью алгоритмы distance
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

#define all(s) s.begin(), s.end()

using namespace std;

string itos(int v) {
    stringstream os;
    os << v;
    string s;
    os >> s;

    return s;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    set <string> s;
    for (int i(1); i <= n; i++) {
        s.insert(itos(i));
    }

    cout << distance(s.begin(), s.find(itos(k)))+1;

    return 0;
}
