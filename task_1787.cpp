#include <iostream>

int main(int argc, char * argv []) {

    int k_turn;
    int n_minutes;

    std::cin >> k_turn >> n_minutes;

    int sum = 0;
    for (int i = 0; i < n_minutes; ++i) {
        int a_i = 0;
    	std::cin >> a_i;
        sum += a_i;
    }

    int rest = sum - k_turn * n_minutes;
    if (rest < 0) rest = 0;

    std::cout << rest << std::endl;

    return 0;
}



