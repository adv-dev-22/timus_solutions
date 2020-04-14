#include <iostream>
#include <cmath>
#include <iomanip>
#include <list>

int main(int argc, const char * argv []) {

    double a;
    std::list<double> buffer;
    while (std::cin >> a) {
        buffer.push_back(a);
    }

    for (std::list<double>::const_reverse_iterator itr = buffer.crbegin(); itr != buffer.crend(); ++itr) {
        std::cout << std::fixed << std::setprecision(4) << std::sqrt(*itr) << std::endl;
    }

    return 0;
}
