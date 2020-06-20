#include <iostream>
#include <cmath>

//size_t

int main(int argc, char * argv []) {

    size_t R = 0;
    std::cin >> R;

    unsigned long long filled_counter = 0;

    size_t i = R;
    for (size_t j = 0; j < R; ++j) {

        const long double y = j;
        const long double r = R;
        const long double x = sqrt((r - y) * (r + y));
        const unsigned long long numb_x = static_cast<size_t>(ceil(x));

        filled_counter += numb_x;
    }

    filled_counter *= 4;
    std::cout << filled_counter << std::endl;

    return 0;
}

// End of the file
