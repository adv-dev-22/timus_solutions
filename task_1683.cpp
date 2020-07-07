#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char * argv []) {

    unsigned int L = 0;
    std::cin >> L;

    if (1 == L) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<unsigned int> trace(0);

    for (;;) {

        L = ceil(static_cast<double>(L) / 2.0);
        trace.push_back(L);

        if (1 == L) break;
    }

    std::cout << trace.size() << std::endl;
    for (auto item : trace) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}

// End of the file
