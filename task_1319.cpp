#include <iostream>
#include <vector>

int S(const int k, const int n) {

    const int m = n - k - 1;
    return m * (m + 1) / 2 + 1;
}

int main(int argc, char * argv[]) {

    int n{0};
    std::cin >> n;

    std::vector<int> a(n, 0);
    std::vector<int> b(n, 0);

    // top row
    for (int k = 0; k < n; ++k) {
        a[k] = S(k, n);
    }
    // left column
    b[0] = S(0, n);
    for (int k = 1; k < n; ++k) {
        b[k] = b[k - 1] + n - k + 1;
    }

    for (int i = 0; i < n; ++i) {

        // left-bottom triangle
        for (int j1 = 0; j1 < i; ++j1) {
            const int value = b[i - j1] + j1;
            std::cout << value << " ";
        }
        // upper-right triangle
        for (int j2 = i; j2 < n; ++j2) {
            const int value = a[j2 - i] + i;
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



