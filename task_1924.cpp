#include <iostream>
#include <string>

int main(int argc, char * argv []) {

    int n;
    std::cin >> n;

    const std::string str_1("grimy");
    const std::string str_2("black");

    if (1 == ((n+1)/2) % 2) {
        std::cout << str_1 << std::endl;
    } else {
        std::cout << str_2 << std::endl;
    }
    return 0;
}
