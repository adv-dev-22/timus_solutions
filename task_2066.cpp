#include <iostream>

int main(int argc, char * argv []) {

    int a, b, c;
    std::cin >> a >> b >> c;

    if (b < a) std::swap(a, b);
    if (c < a) std::swap(a, c);

    int min_bc = std::min(b, c);
    int abc_min = a - b * c;

    if (0 == min_bc || 1 == min_bc) {
        abc_min = a - b - c;
    }

    std::cout << abc_min << std::endl;

    return 0;
}


// End of the file

