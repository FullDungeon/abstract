/*
* ------------ КОНДИЦИОНЕРЫ ------------
& библиотеки алгоритмов
~ метод_двух_указателей
? Как решаем задачу? Использщуем метод двух указателей: для начала сортируем классы по требуемой мощности и кондиционеры сначала по цене, а потом по мощности. Все по возрастанию. Далее перебираем кондиционеры, для каждого кондиционера внутренним укзаателем j перебираем классы, которые монжо отопить текущим кондиционером j. И поддерживаем сумму. Все.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define all(s) s.begin(), s.end()

using namespace std;

using line = vector <int>;

struct cond {
    int w, p;

    cond() {
        cin >> w >> p;
    }
};

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;

    line d(n);
    for (auto& i : d)
        cin >> i;

    sort(all(d));

    cin >> m;

    /// <мощность, стоимость>
    vector <cond> p(m);

    sort(all(p), [](cond a, cond b) { return a.p < b.p || (a.p == b.p && a.w < b.w); });

    // code: метод двух указателей
    int sum(0);
    int j(0);

    // перебор кондиционеров
    for (int i(0); i < m; i++) {
        
        // перебор классов
        while (j < n) {
            if (d[j] <= p[i].w) {
                sum += p[i].p;
                j++;
                continue;
            }

            break;
        }
    }

    cout << sum;

    return 0;
}
