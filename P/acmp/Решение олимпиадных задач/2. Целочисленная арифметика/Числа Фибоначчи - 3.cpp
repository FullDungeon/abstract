/*
* ------------ ЧИСЛА ФИБОНАЧЧИ - 3 ------------
& целые числа
~ gcd
? Задача на знание войства НОД: gcd(Fi, Fj) = Fgcd(i, j)
? То есть, если выразить это словами: НОД двух чисел Фибоначчи с порядковыми номерами i и j равен числу Фибоначчи с номером gcd(i, j)

warning: gcd(Fi, Fj) = Fgcd(i, j)
*/

#include <iostream>
#include <vector>

using namespace std;

using T = long long;

T gcd(T a, T b) {
    if (!b)
        return a;

    return gcd(b, a%b);
}

int main() {
    // ...
    T i, j;
    cin >> i >> j;

    int k = gcd(i, j);

    int a(0), b(1);

    while (--k) {
        b += a;
        a = b - a;

        b %= 1000000000;
    }
    
    cout << b;

    return 0;
}