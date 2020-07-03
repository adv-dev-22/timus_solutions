#include <iostream>

int main(int argc, char * argv []) {

    int n;
    std::cin >> n;

    int a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;

    int sum = a1 + a2 + a3;
    int index = 2;

    for (int k = 0; k + 3 < n; ++k) {

        std::cin >> a1;

        const int upd_sum = a2 + a3 + a1;

        if (upd_sum > sum) {
            sum = upd_sum;
            index = k + 3;
        }
        a2 = a3;
        a3 = a1;
    }

    std::cout << sum << " " << index << std::endl;

    return 0;
}

// End of the file
