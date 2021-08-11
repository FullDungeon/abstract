/*
* ------------ Рунныек слова ------------
& простые задачи
~ 
? С этой задачей я каждый раз тоже ооооочень долго мучаюсь (как и с IP-адресом)...

? Нужно помнить, что первая буква строки обязательно должан быть заглавной! И в конце нужно приписать одну заглавную букву, чтобы цикл проверил самое последнее слово.

*/

#include <iostream>
#include <string>

#define all(s) s.begin(), s.end()

using namespace std;

int main() {
    // ...
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    s = s + "E";

    if (islower(s[0])) {
        cout << "No";
        return 0;
    }

    int leng(3);
    for (auto c : s) {
        if (isupper(c)) {
            if (leng < 2 || leng > 4) {
                cout << "No";
                return 0;
            }

            leng = 1;
        }
        else {
            leng++;
        }
    }

    cout << "Yes";

    return 0;
}
