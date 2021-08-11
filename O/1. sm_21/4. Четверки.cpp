#include <iostream>
#include <vector>
#include <map>

#define sqr(a) ((a)*(a))
#define all(d) d.begin(), d.end()

using namespace std;

typedef vector <int> line;
typedef vector <line> matrix;

int main() {
	// ...
	int n, amount(0);
	cin >> n;

	matrix d(n, line(n));
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			cin >> d[i][j];

			if (i && j) {
				map <int, int> m;

				m[d[i][j]]++;
				m[d[i-1][j]]++;
				m[d[i][j-1]]++;
				m[d[i-1][j-1]]++;

				amount += (m.size() == 4);
			}
		}
	}

	cout << amount;
}