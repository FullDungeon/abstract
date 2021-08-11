/*
* ------------ ПИЦЦА ------------
& Дианмика - 1
~ одномерная_динамика
? Если нарисовать несколько случаев, то становится понятно, что каждый i-ый разрес увеличивает кол-во кусков на i. 
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

	line d(n + 1);
	d[0] = 1;
	
	for (int i(1); i <= n; i++) {
		d[i] += d[i - 1] + i;
	}

	cout << d[n];
	
	return 0;
}