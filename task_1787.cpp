#include <iostream>

int main(int argc, char * argv []) {

    int k_turn;
    int n_minutes;

    std::cin >> k_turn >> n_minutes;
    int rest = 0;
    for (int i = 0; i < n_minutes; ++i) {
        int a_i = 0;
    	std::cin >> a_i;

        rest += a_i;
        if (rest - k_turn < 0) rest = 0;
        else rest -= k_turn;
    }

    std::cout << rest << std::endl;

    return 0;
}
