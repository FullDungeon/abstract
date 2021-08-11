#include <iostream>

using namespace std;

int main() {
	// ...
	int p, t, k, amount(0);
	cin >> p >> t >> k;

	while (p > 0) {
		p -= t;
		p += p * k / 100;
		amount++;
	}

	cout << amount;
}