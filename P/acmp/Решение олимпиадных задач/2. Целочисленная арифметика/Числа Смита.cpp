/*
* ------------ ЧИСЛА ФИБОНАЧЧИ - 3 ------------
& целые числа
~ факторизация ~ простые_числа
? ничего сложного, просто нужно прочитать внимательно условие и обратить внимание на то, что числом Смита может быть только
? простое число. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

using line = vector <int>;

int digitSum(int p) {
    int s(0);

    while (p) {
        s += p % 10;
        p /= 10;
    }

    return s;
}

// факторизация с проверкой на простоту
int factorizationSum(int p) {
    double e = sqrt(p + .0) + 1;

    int i(2);
    int sum(0);

    bool isSimple = true;

    while (i < e) {
        if (p % i == 0) {
            sum += digitSum(i);
            isSimple = false;
            p /= i;
            continue;
        }

        i++;
    }

    if (p > 1 && !isSimple) {
        sum += digitSum(p);
    }

    return sum;
}

int main() {
    // ...
    int p;
    while (cin >> p) {
        int f = factorizationSum(p);
        int d = digitSum(p);

        cout << (f == d ? 1 : 0);
    }


    return 0;
}
