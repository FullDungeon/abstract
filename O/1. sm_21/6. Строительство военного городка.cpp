#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define all(p) p.begin(), p.end()

using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long     T;
typedef vector <T>    line;
typedef vector <line> matrix;

struct point {
	T x, y;

	point() {
		cin >> x >> y;
	}
};

T gcd(T a, T b) {
	if (!b)
		return a;

	return gcd(b, a%b);
}

T getAmount(point a, point b) {
	T dx = abs(a.x - b.x);
	T dy = abs(a.y - b.y);

	if      (!dx) return dy + 1;
	else if (!dy) return dx + 1;
	else          return gcd(dx, dy) + 1;
}

int main() {
	// ...
	int n, amount(0);
	cin >> n;

	vector <point> d(n);
	d.push_back(d.front());

	for (int i(1); i < d.size(); i++) {
		amount += getAmount(d[i], d[i-1]);
	}

	cout << amount - n;
}