#include <iostream>
#include <cmath>

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;

    if (0 == N) {
        std::cout << 1 << std::endl;
        return 0;
    }

    const bool sign_bit = std::signbit(static_cast<double>(N));

    N = std::abs(N);

    long long sum = N * (N + 1) / 2;

    if (sign_bit) {
        sum -= 1;
        sum = -sum;
    }

    std::cout << sum << std::endl;

    return 0;
}

// End of the file
