#include <iostream>
#include <string>

bool last_digit_is_even(const std::string lock_code) {

    const char last_ch = lock_code[3];

    if ('0' == last_ch || '2' == last_ch || '4' == last_ch ||
        '6' == last_ch || '8' == last_ch) {
        return true;
    }

    return false;
}

int main(int argc, char * argv []) {

    std::string lock_1;
    std::string lock_2;

    std::cin >> lock_1 >> lock_2;

    if (last_digit_is_even(lock_1) || !last_digit_is_even(lock_2)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
