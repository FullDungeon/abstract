/*
* ------------ Сортировка вставками ------------
^ 
? 
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

using TYPE  = int; 

// LENG - должно быть равно числу нулей в BASE!!!
int LENG    = 3;    // кол-во цифр в разряде 
int BASE    = 1000; // основание
int MAX_LEN = 100;  // максимальное кол-во разрядов

struct BigInt {
    int amount;
    vector <TYPE> d;

    BigInt() {
        d.resize(MAX_LEN);
    }
    BigInt(string s) {
        d.resize(MAX_LEN);

        int j(0);
        for (int i(s.size() - 1); i >= 0; i -= LENG) {
            int start = i - LENG + 1;

            if (start < 0)
                start = 0;

            string str = s.substr(start, i - start + 1);
            d[j++] = atoi(s.substr(start, i - start + 1).c_str());
        }

        amount = j;
    }

    void input() {
        string s;
        cin >> s;

        int j(0);
        for (int i(s.size() - 1); i >= 0; i -= LENG) {
            int start = i - LENG + 1;

            if (start < 0)
                start = 0;

            string str = s.substr(start, i - start + 1);
            d[j++] = atoi(s.substr(start, i - start + 1).c_str());
        }

        amount = j;
    }

    void output() {
        cout << d[amount - 1];
        for (int i(amount - 2); i >= 0; i--)
            cout << setfill('0') << setw(LENG) << d[i];
    }
};

bool operator < (const BigInt& a, const BigInt& b) {
    if (a.amount == b.amount) {
        for (int i(a.amount - 1); i >= 0; i--) {
            if (a.d[i] != b.d[i])
                return a.d[i] < b.d[i];
        }
    }

    return a.amount < b.amount;
}

BigInt operator + (const BigInt& a, const BigInt& b) {
    BigInt c;
    c.amount = max(a.amount, b.amount);

    TYPE r = 0;
    for (int i(0); i < (c.amount | r); i++) {
        c.d[i] = a.d[i] + b.d[i] + r;

        if (c.d[i] >= BASE) {
            c.d[i] -= BASE;
            r = 1;
        }
        else {
            r = 0;
        }
    }

    if (c.d[c.amount])
        c.amount++;

    return c;
}

int main() {
    // ...
    BigInt a, b, c;
    a.input();
    b.input();

    c = a + b;

    c.output();

    return 0;
}