#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

const int    UNDEFINED_VALUE = -1;
const double NUMERIC_EPS = 1e-10;

// Global vector to avoid pass it in the function.
std::vector<int> opt_quad(1, 1);

int optim_q(const int number);

int main(int argc, char * argv []) {

    int N = 0;
    std::cin >> N;

    // UNDEFINED_VALUE means that value has not been precomputed yet.
    opt_quad.resize(N + 1, UNDEFINED_VALUE);

    const int number = optim_q(N);
    std::cout << number << std::endl;

    return 0;
}

int optim_q(const int number) {

    if (opt_quad[number] != UNDEFINED_VALUE) return opt_quad[number];

    if (0 == number) return 0;
    if (1 == number) return 1;

    const int sq_n = floor(sqrt(number));

    if (number == sq_n * sq_n) {
        opt_quad[number] = 1;
        return opt_quad[number];
    }

    int min_opt = std::numeric_limits<int>::max();

    for (int jmp = 1; jmp <= sq_n; ++jmp) {

        const int opt_q_val = optim_q(number - jmp * jmp);
        min_opt = std::min(min_opt, opt_q_val);
    }

    opt_quad[number] = 1 + min_opt;
    return 1 + min_opt;
}

// End of the file

