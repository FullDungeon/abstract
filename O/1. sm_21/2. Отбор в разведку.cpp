#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> line;

int main() {
	// ...
	int n;
	cin >> n;

	line d(n + 10);
	d[3] = 1;

	int o(2), e(2);
	for (int i(4); i <= n; i++) {
		d[i] = d[o] + d[e];

		(o == e ? e : o)++;
	}

	cout << d[n];
}