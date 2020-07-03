#include <iostream>
#include <string>

int main(int argc, char * argv []) {

    int m, n;
    std::cin >> m >> n;

    const std::string str_1("[:=[first]");
    const std::string str_2("[second]=:]");

    if (0 == (m * n) % 2) {
        std::cout << str_1 << std::endl;
    } else {
        std::cout << str_2 << std::endl;
    }
    return 0;
}


