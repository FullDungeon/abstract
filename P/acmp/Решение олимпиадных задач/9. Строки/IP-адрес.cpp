/*
* ------------ IP-адрес ------------
& простые задачи
~ 
? С этой задачей я каждый раз ооооочень долго мучаюсь...

? Задача простая, но... Нужно помнить, что числа между точками могут быть больше чем int... А еще в конце надо точку приписать

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // ...
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    s += '.';

    long long temp = -1;
    for (auto c : s) {

        if (c == '.') {

            if (temp < 0 || temp > 255) {
                cout << "Bad";
                return 0;
            }

            temp = -1;
        }
        else {
            temp = (temp == -1 ? 0 : temp) * 10 + (int)c - 48;
        }
    }

    cout << "Good";

    return 0;
}
