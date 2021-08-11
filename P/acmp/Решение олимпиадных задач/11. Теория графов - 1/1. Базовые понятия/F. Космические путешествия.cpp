/*
* ------------ ЭВОЛЮЦИЯ ------------
& базовые понятия
? Если из вершины выходит более чем одно ребро, то она важная. А так как граф неориентированный, то количество ребер для вершины i равно окл-ву появлений числа i во входных данных.
*/

#include <iostream>
#include <vector>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	line d(n);
	for (int i(0); i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		d[a - 1]++;
		d[b - 1]++;
	}

	int amount(0);
	for (auto i : d)
		amount += i > 1;

	cout << amount;
	
	return 0;
}