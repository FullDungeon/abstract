/*
* ------------ ПРЕОБРАЗОВАНИЕ МНОГОКЛЕТОЧНЫХ ------------
& перестановки
~ STL
? Оказывается, если взять число, представленное строкой в двоичной системе счисления, и следующую лексикографическую строку перевести в
? десятичное число, то получим ответ.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
 
#define all(s) s.begin(), s.end()
 
using namespace std;
 
using T = unsigned long long;
 
T bin(string s) {
    T val(0);
    T bin(1);
 
    for (int i(s.size() - 1); i >= 0; i--) {
        val += bin * (s[i] == '1');
        bin *= 2;
    }
 
    return val;
}
 
int main() {
    // ...
    T n;
    cin >> n;
 
    bitset <34> b = n;
    string s = b.to_string();
 
    next_permutation(all(s));
 
    cout << bin(s);
 
    return 0;
}