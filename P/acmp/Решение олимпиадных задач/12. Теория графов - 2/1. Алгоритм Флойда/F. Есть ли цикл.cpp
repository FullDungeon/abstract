/*
* ------------ Есть ли цикл ------------
& алгоритм флойда
~ dfs_проверка_на_ацикличность ~ флойд_проверка_на_наличие_цикла
? Можно решать разными алгоритмами. Первый способ: dfs для ориентированного графа. Главное помнить, что граф может состоять из нескольих компонент связности.  
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

const int WHITE = 0;
const int GRAY  = 1;
const int BLACK = 2;

line color;
matrix d;

bool dfs(int curr) {
	color[curr] = GRAY;

	for (auto next : d[curr]) {
		if (color[next] == WHITE) {
			dfs(next);
		}
		if (color[next] == GRAY) {
			return true; // цикл найден
		}
	}

	color[curr] = BLACK;
	return false;
}

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	d.resize(n);
	color.resize(n);
	
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			int v;
			cin >> v;

			if (v) {
				d[i].push_back(j);
			}
		}
	}

	for (int i(0); i < n; i++) {
		if (dfs(i)) {
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
	
	return 0;
}

/*
& решение с помощью алгоритмы Флойда
? изменим входные данные: 0 заменим на INF (признак того, что между данными вершинами нет пути), а 1 на -1. А теперь проверим, есть ли в графе отрицательный цикл.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int INF = 0x3f3f3f3f;


int main() {
    // ...
    int n;
    cin >> n;

    matrix d(n, line(n));
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            cin >> d[i][j];

            d[i][j] = (d[i][j] ? -1 : INF);
        }
    }
    
    for (int k(0); k < n; k++) {
        for (int i(0); i < n; i++) {
            for (int j(0); j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF ) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // ограничение снизу
                }
            }
        }
    }

    for (int i(0); i < n; i++) {
        // проверка на наличие циклов
        if (d[i][i] < 0) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}