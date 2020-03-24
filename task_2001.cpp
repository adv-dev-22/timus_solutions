#include <iostream>

// w1, w2, y1, y2

// a1 = w1 + y1
// b1 = w2 + y2

// a2 = w1 + y1 + y2
// b2 = w2

// a3 = w1
// b3 = w2 + y1 + y2


int main(int argc, char * argv []) {

    int a1, b1, a2, w2, w1, b3;  // b2, a3

    std::cin >> a1 >> b1;
    std::cin >> a2 >> w2;
    std::cin >> w1 >> b3;

    int y1 = a1 - w1;
    int y2 = b1 - w2;

    std::cout << y1 << " " << y2 << std::endl;

    return 0;
}
