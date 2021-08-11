//* Лесенки и столовские котлеты
#include <iostream>

int n, d[201] = { 1 };

int main() {
    // ...
    std::cin >> n;

    for (int i(1); i <= n; i++) 
        for (int j(n); j >= i; j--)
            d[j] += d[j - i];

    std::cout << d[n];
}