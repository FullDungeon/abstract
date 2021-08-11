/*
* ------------ ГОДОВОЙ БАЛАНС ------------
& сортировка - 1
~ сортировка_пузырьком ~ stoi
? Всего может быть 4 случая и в каждом случае, в зависимости от положения и знака числа, они сортируюются по разному:
> положительное + положительное = по возрастанию + по убыванию
> положительное + отрицательное = по возрастанию + по возрастанию
> отрицательное + положительное = по убыванию    + по убыванию
> отрицательное + отрицательное = по убыванию    + по возрастанию

? Сортировка производится пузырьком - главное не забыть, что число не может начинаться  с нуля!!!
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int FREE = 0;
const int USED = 1;

using line = vector <int>;
using matrix = vector <line>;

void BubleSort(string& s, bool reverse) {
    int n = s.size();

    int start = s[0] == '-'; // знак числа не учствует в сортировке

    for (int i(0); i < n - 1; i++) {
        for (int j(start); j < n - i - 1; j++) {
            bool is = (reverse ? s[j] < s[j + 1] : s[j] > s[j + 1]);

            if (is && (j != start || s[j + 1] != '0'))
                swap(s[j], s[j + 1]);
        }
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    BubleSort(a, a[0] != '-');
    BubleSort(b, b[0] == '-');

    cout << stoi(a) - stoi(b);

    return 0;
}