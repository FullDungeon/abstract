/*
* ------------ ЕДИНИЧНЫЙ НОД ------------
& нод и нок
~ gcd
? задача на свойства чисел: НОД двух чисел, составленных из m и n единиц равен числу из gcd(n, m)
*/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (!b)
        return a;

    return gcd(b, a % b);
}

int main() {
    // ...
    int n, m;
    cin >> n >> m;

    for (int i(0); i < gcd(n, m); i++)
        cout << 1;

    return 0;
}