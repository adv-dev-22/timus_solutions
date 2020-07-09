#include <iostream>
#include <string>
#include <algorithm>

int main() {

    int N{0};
    std::cin >> N;

    int counter[3] = {0, 0, 0};

    std::string name1;
    std::string name2;

    for (int k = 0; k < N; ++k) {
        std::cin >> name1 >> name2;
        if (name1 == "Emperor") {
            ++counter[0];
        } else if (name1 == "Macaroni") {
            ++counter[1];
        } else {
            ++counter[2];
        }
    }

    const auto itr = std::max_element(counter, counter + 3);
    const int pos = itr - counter;
    if (0 == pos) {
        std::cout << "Emperor Penguin" << std::endl;
    } else if (1 == pos) {
        std::cout << "Macaroni Penguin" << std::endl;
    } else {
        std::cout << "Little Penguin" << std::endl;
    }

    return 0;
}



// End of the file
