#include <iostream>
long long n, m, nc;

int main() {
    std::cin >> n >> m;
    std::cout << std::min(n, m) << ' ';
    if (n == m) {
        std::cout << 1;
        return 0;
    }
    while (n > 1 || m > 1) { // 10 3
        if (n > m) {
            nc += n / m; // 3
            n -= m * (n / m); // 1
        }
        else {
            nc += m / n;
            m -= n * (m / n);
        }
    }
    std::cout << nc;
    return 0;
}