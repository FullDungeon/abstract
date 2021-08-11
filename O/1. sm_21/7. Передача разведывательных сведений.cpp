#include <iostream>
#include <vector>
#include <map>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

int main() {
    // ...
    int m, n, t;
    cin >> m >> n >> t;

    line mx(t + 1);
    line p(2);
    p[0] = m;
    p[1] = n;

    int mxi(0);
    for (int i(0); i <= t; i++) {
        if (mx[i] || !i) {
            for (int j(0); j < p.size(); j++) {
                if (i + p[j] <= t) {
                    mx[i + p[j]] = max(mx[i + p[j]], mx[i] + 1);
                }
            }
        }

        if (mx[i]) {
            mxi = i;
        }
    }

    cout << mx[mxi];
    if (mxi != t)
        cout << " " << t - mxi;

    return 0;
}