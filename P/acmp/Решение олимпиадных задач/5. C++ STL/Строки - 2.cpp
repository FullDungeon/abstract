/*
* ------------ СТРОКИ - 2 ------------
& Структкры данных
~ STL ~ multiset
? Для решения запомним все строки исходного множества S в массив d и будем перебирать все пары d[i] и d[j], i может быть равно j.
? Крмое того, все строки добавим в multiset <string> s - он будет нужен для быстрой проверки на принадлежность некоторой строки p
? к исходному множеству S.
? РЕШЕНИЕ
? Перебираем все пары строк и их канкатенацией получаем строку p. Суть решения в том, что если p = "aaaa" и в исходном множестве S
? строка "аааа" встречается 4 раза, то и в ответе надо учитывать ее четыре раза. А multiset позволяет быстро (за log(N)) проверять
? принадлежность строки ко множеству.

warning: использование multiset, поиска find в нем и операции erase
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    // ...
    ios::sync_with_stdio(false);
    string temp;
    vector <string> d;
    multiset <string> s;

    while (true) {
        cin >> temp;

        if (temp == "ENDOFINPUT")
            break;

        d.push_back(temp);
        s.insert(temp);
    }

    int amount(0);
    for (int i(0); i < d.size(); i++) {
        for (int j(0); j < d.size(); j++) {
            string p = d[i] + d[j];
            
            auto it = s.begin(); // просто инициализация (auto тут тоже самое, что set<string>::iterator)

            // если строка p в исходном множестве встречается 4 раза, то этот цикл учтет это в ответе
            while ((it = s.find(p)) != s.end()) {
                s.erase(it);
                amount++;
            }

        }
    }

    cout << amount;

    return 0;
}