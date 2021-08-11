/*
* ------------ АГЕНТЫ ------------
& Дианмика - 1
~ одномерная_динамика
? Решение задачи аналогично решению задачи Гвоздики, но с тем отличием, что там считались расстояния между гвоздиками, а тут за аналогичное значение берется риск старшего агента.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

using line = vector <int>;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector <pair <int, int>> d(n);
	for (auto& i : d)
		cin >> i.first >> i.second;

	sort(d.begin(), d.end());

	// code: тут будут хранится риски раскрытия для каждой i-й группы, которая состоит из i и i-1 агентов
	line p(n);
	for (int i(1); i < n; i++) {
		p[i] = d[i].second; // code: риску подвергается только старший агент!
	}

	// code: вычисление ответов на подзадачу
	line r(n);
	
	r[0] = 0;		
	r[1] = p[1];	
	
	if (n > 2) {
		r[2] = r[1] + p[2]; 

		for (int i(3); i < n; i++) {
			r[i] = p[i] + min(r[i - 1], r[i - 2]);
		}
	}

	cout << r[n - 1];
	
	return 0;
}