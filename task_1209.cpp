#include <iostream>
#include <cmath>

int get_digit(const long long s) {

    if (1 == s) return 1;

    const double r = 0.5 * sqrt(static_cast<double>(s) + 0.125) * sqrt(8.) - 0.5;
    long long left_pos = floor(r);

    const long left_bound = left_pos * (left_pos + 1) / 2;

    if (s == left_bound + 1) return 1;
    return 0;
}

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;

    for (int i = 0; i < N; ++i) {

        long long n_pos;
        std::cin >> n_pos;

        std::cout << get_digit(n_pos) << std::endl;
    }

    return 0;
}



// End of the file
