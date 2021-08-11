/*
* ------------ КОМПЬЮТЕРНАЯ ИГРА ------------
& Дианмика - 2
~ одномерная_динамика
? рассматриваем i-ю платформу: на нее можно попасть с i-1 (тут мы прибавим расстояние между i и i-1 и ответ для n = i-1), или с i-2 (ответ для n = i-2 и утроенное расстояние между платформами i и i-2).
*/

#include <iostream>
#include <vector>

using namespace std;

using line = vector <int>;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	line d(n);
	for (auto& i : d)
		cin >> i;

	line p(n);
	p[0] = 0;			     // герой находится на первой платформе
	p[1] = abs(d[1] - d[0]); // на второй платформе
	
	for (int i(2); i < n; i++) {
		p[i] = min(3 * abs(d[i] - d[i - 2]) + p[i - 2], abs(d[i] - d[i - 1]) + p[i - 1]);
	}

	cout << p[n - 1];
	
	return 0;
}