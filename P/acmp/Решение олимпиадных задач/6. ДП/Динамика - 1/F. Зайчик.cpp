/*
* ------------ ЗАЙЧИК ------------
& Дианмика - 1
~ одномерная_динамика ~ динное_длинное_сложение
? просто перебор и несложная динамика. Единственная трудность - длинное сложение.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

using T = vector <int>;
using line = vector <T>;

T operator += (T& a, const T& b) {
	int n = max(a.size(), b.size());

	for (int i(0); i < n; i++) {
		if (i == a.size())
			a.push_back(0);

		a[i] += (i < b.size() ? b[i] : 0);

		if (a[i] > 9) {
			if (i + 1 == a.size())
				a.push_back(0);

			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}

	return a;
}

void out(T p) {
	for (auto i = p.rbegin(); i != p.rend(); i++)
		cout << *i;
}

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n, k;
	cin >> k >> n;

	line d(n + 10);
	d[0] = { 1 };
	d[1] = { 1 };

	for (int i(2); i <= n; i++) {
		for (int j(1); j <= k; j++) {
			if (i - j >= 0)
				d[i] += d[i - j];
		}
	}

	out(d[n]);
	
	return 0;
}