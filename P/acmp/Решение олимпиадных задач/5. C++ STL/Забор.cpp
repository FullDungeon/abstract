/*
* ------------ ЗАБОР ------------
& структуры данных
~ map ~ полиномиальное_хеширование
? все просто: запомним в map под хешами шаблонов их номера. Далее будем по хэшу каждого забора смотреть, есть ли такой шаблон, если да - выводить его номер, который хранится в map.

? во втором решении все то же самое, но вместо хешей используются сами массивы. По времени решение не уступает, но по памяти значительно.
*/

//^ время:  0,874 сек.
//^ память: 532 Кб 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

using T = unsigned long long;

int l, m, n;
int ok, bad;

// хеширование
T base = 8199;
vector <T> powers;

void preporcess(int n) {
    powers.resize(n + 1);

    powers[0] = base;
    for (int i(1); i < powers.size(); i++)
        powers[i] = powers[i - 1] * base;
}

// ввод и хеширование
T inputLine() {
    T temp(0); // хэш текущего забора/шаблона

    for (int i(0); i < l; i++) {
        T v;
        cin >> v;

        temp += v * powers[i];
    }

    return temp;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> l >> m >> n;

    preporcess(l);

    // ввод шаблонов
    map <T, int> templates; // ! важно то, что я храню именно номера по хэшам, а не наоборот

    for (int i(0); i < m; i++) {
        int p; // номер шаблона
        cin >> p;

        templates[inputLine()] = p;
    }

    // ввод заборов
    for (int i(0); i < n; i++) {
        int number = templates[inputLine()];

        if (number) {
            ok++;
            cout << number << '\n';
        }
        else {
            bad++;
            cout << "-\n";
        }
    }

    cout << "OK=" << ok << " BAD=" << bad;

    return 0;
}

//^ время:  0,874 сек.
//^ память: 7,4 Мб 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

using T = unsigned long long;

using line = vector <int>;

int l, m, n;
int ok, bad;

// ввод и хеширование
line inputLine() {
    line temp(l);

    for (auto& i : temp)
        cin >> i;

    return temp;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> l >> m >> n;

    // ввод шаблонов
    map <line, int> templates;

    for (int i(0); i < m; i++) {
        int p; // номер шаблона
        cin >> p;

        templates[inputLine()] = p;
    }

    // ввод заборов
    for (int i(0); i < n; i++) {
        int number = templates[inputLine()];

        if (number) {
            ok++;
            cout << number << '\n';
        }
        else {
            bad++;
            cout << "-\n";
        }
    }

    cout << "OK=" << ok << " BAD=" << bad;

    return 0;
}