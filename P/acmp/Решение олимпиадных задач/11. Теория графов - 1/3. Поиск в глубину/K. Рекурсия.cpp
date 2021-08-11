/*
* ------------ РЕКУРСИЯ ------------
& поиск в глубину
~ dfs ~ map
? основная сложность: представить все данные в виде графа - списков смежности. Для этого используется map <string, int>. После того как граф получен, мы перебираем все строки proc в том порядке, в котором они были даны в файле (n строк, не все, которые были введены). Для каждой строки запрускаем dfs (ее номер в графе берем из map) и если обход попал в нее еще раз, то выводим "YES" - процедура потенциально рекурсивна.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int n;
matrix d;
line used;
map <string, int> h;  // номера процедур по их названиям
vector <string> proc; // массив названий процедур в исходном порядке

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int addProcedure(string p) {
    if (h.count(p))
        return h[p];

    return h[p] = h.size();
}

int is, root;

void dfs(int curr) {
    used[curr] = GRAY;

    for (auto next : d[curr]) {
        if (!used[next]) {
            dfs(next);
        }
        if (next == root) {
            is = true;
        }
    }
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n;

    d.resize(n);
    used.resize(n);
    for (int i(0); i < n; i++) {
        string r;
        cin >> r;

        int a = addProcedure(r);
        proc.push_back(r);

        int m;
        cin >> m;

        for (int j(0); j < m; j++) {
            string sub;
            cin >> sub;

            int b = addProcedure(sub);

            d[a].push_back(b);
        }

        cin >> r; // чтение разделителя
    }

    // решение
    for (auto p : proc) {
        fill(used.begin(), used.end(), WHITE);

        is = false;
        root = h[p];
        dfs(root);

        cout << (is ? "YES\n" : "NO\n");
    }

    return 0;
}