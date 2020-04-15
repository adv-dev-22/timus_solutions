#include <iostream>

int cells_under_attac(const std::string & pos_str) {

    int value = 0;

    const char s0 = pos_str[0];
    const char d1 = pos_str[1];

    //std::cout << s0 << d1 << std::endl;

    if (s0 >= 'c' && d1 <= '7') value += 1;
    if (s0 >= 'b' && d1 <= '6') value += 1;

    if (s0 <= 'f' && d1 <= '7') value += 1;
    if (s0 <= 'g' && d1 <= '6') value += 1;

    if (s0 <= 'f' && d1 >= '2') value += 1;
    if (s0 <= 'g' && d1 >= '3') value += 1;

    if (s0 >= 'c' && d1 >= '2') value += 1;
    if (s0 >= 'b' && d1 >= '3') value += 1;

    return  value;
}

int main(int argc, char * argv []) {

    int N;
    std::cin >> N;

    std::string position;

    for (int i = 0; i < N; ++i) {
        std::cin >> position;
        std::cout << cells_under_attac(position) << std::endl;
    }

    return 0;
}



// End of the file
