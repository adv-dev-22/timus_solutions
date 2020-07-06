#include <iostream>
#include <vector>
#include <string>

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;

    std::vector<std::string> data(N, std::string(""));
    for (int k = 0; k < N; ++k) {
        std::cin >> data[k];
    }

    std::string s1;
    std::cin >> s1;

    for (int k = 0; k < N; ++k) {
        if (data[k][0] == s1[0]) {
            std::cout << data[k] << std::endl;
        }
    }

    return 0;
}

// End of the file
