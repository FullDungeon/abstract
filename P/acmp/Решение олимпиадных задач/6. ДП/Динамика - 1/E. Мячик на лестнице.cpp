/*
* ------------ МЯЧИК НА ЛЕСТНИЦЕ ------------
& Дианмика - 1
~ одномерная_динамика
? ничего сложного, главное, использовать тип long long
*/

#include <iostream>
#include <vector>

using namespace std;

using line = vector <long long>;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	line d(n + 10);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i(4); i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	cout << d[n];
	
	return 0;
}