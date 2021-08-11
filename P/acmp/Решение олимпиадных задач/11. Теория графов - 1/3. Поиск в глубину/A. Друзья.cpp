/*
* ------------ ДРУЗЬЯ ------------
& поиск в глубину
~ dfs
? Итак, дан граф, и если у вершины графа нет потомков, то у человека, которого она моделирует, нет друзей. Будем пользоваться обходом в глубину, для нахождения friends[i] друзей для каждого i-го человека. А в ответ выведем friends[s - 1]. Как будем заполнять этот массив frineds? Как только мы вышли из рекурсии на curr (__1__), то это значит, что для всех потомков curr кол-во друзей уже подсчитано (базовый случай - когда нет потомокв и, соответственно, друзей). Тогда кол-во друзей у curr равно кол-ву друзей у next плюс один (единица учитывает самого человека с номером next) и ПЛЮС (!!!!!!!) то количество друзей, которое человек curr уже имел до этого (__2__).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

line used, friends;
matrix d;

void dfs(int curr) {
	used[curr] = true;

	for (auto next : d[curr]) {
		if (!used[next]) {
			dfs(next); // % 1
			friends[curr] += friends[next] + 1; // % 2
		}
	}
}

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;

	d.resize(n);
	used.resize(n);
	friends.resize(n);
	
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			int v;
			cin >> v;

			if (v)
				d[i].push_back(j);
		}
	}

	dfs(s - 1);

	cout << friends[s - 1];
	
	return 0;
}
