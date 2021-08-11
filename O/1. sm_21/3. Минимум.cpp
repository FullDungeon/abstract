#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> line;

int main() {
	// ...
	int n, k;
	cin >> n >> k;

    // вводим данные
	line d(n);
	for (int i(0); i < n; i++) {
		cin >> d[i];
	}

	// решение
	for (int i(0); i < n - k + 1; i++) {
		int mn(d[i]);

		for (int j(i); j < min(i + k, n); j++) {
			mn = min(mn, d[j]);
		}

		if (i) cout << " ";
		cout << mn;
	}
}