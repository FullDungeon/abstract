/*
* ------------ ЦИКЛИЧЕСКИЙ СДВИГ ПОСЛЕДОВАТЕЛЬНОСТИ ------------
& -
~ STL
? Циклический сдвиг последовательности вправо.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using line = vector <int>;

int main() {
    // ...
    string a = "abc";
    string b = "abc";

    rotate(a.rbegin(), a.rbegin() + 1, a.rend()); // циклический сдвиг вправо
    rotate(b.begin(), b.begin() + 1, b.end());    // циклический сдвиг влево

    cout << a; // cab
    cout << b; // bca

    return 0;
}