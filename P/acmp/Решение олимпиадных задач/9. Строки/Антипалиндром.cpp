/*
* ------------ IP-адрес ------------
& алгоритмы на строках
~ палиндром
? СОтвет на задачу такой: если сама строка не является палиндромом, то выводим ее. Если является, проверяем ее снова, но уже без последнего (или первого символа). Если же и эта подстрока является палиндромом, то значит, что вся строка состоит из одинаковых символов и что ответ "NO SOLUTION".

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrom(string s) {
    int i(0), j(s.size() - 1);

    while (i < j) {
        if (s[i] != s[j])
            return false;

        i++, j--;
    }

    return true;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    string s, p;
    cin >> s;

    p = s.substr(0, s.size() - 1);

    if (!isPalindrom(s)) {
        cout << s;
    }
    else if (!isPalindrom(p)) {
        cout << p;
    }
    else {
        cout << "NO SOLUTION";
    }

    return 0;
}