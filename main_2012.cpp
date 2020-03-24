#include <iostream>

int main(int argc, char * argv []) {

    size_t f;
    std::cin >> f;

    const size_t N = 12;
    if ((12 - f) * 45 <= 240) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std:: endl;

    return 0;
}
