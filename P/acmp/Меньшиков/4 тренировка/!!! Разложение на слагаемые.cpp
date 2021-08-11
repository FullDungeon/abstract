/*
* ------------ РАЗЛОЖЕНИЯ НА СЛАГАЕМЫЕ ------------
& меньшиков
~ рекурсия
? будем заполнять массив d цифрами так, что они будут являться разложением числа n на слагаемые. Нужно собоюдать определенный порядок заполнения, чтобы получить все варианты без повторения. Пусть дано n = 5. Тогда один из вариантов разложения представлен ниже:

? 1+1+1+1+1
? ---------
? 1+1+1+2
? 1+2+2
? ---------
? 1+1+3
? 2+3
? ---------
? 1+4

? Пусть изначально массив заполнен нулями. 

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> d;

void out(int n) {
    cout << d[0];

    for (int i(1); i < n; i++)
        cout << '+' << d[i];

    cout << '\n';
}

void rec(int index, int ost, int left) {
    if (ost < 0)
        return;

    if (ost == 0) {
        if (index > 1)
            out(index);

        return;
    }

    for (int i(left); i <= ost; i++) {
        d[index] = i;
        rec(index + 1, ost - i, i);
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    d.resize(n, 1);
    rec(0, n, 1);

    return 0;
}