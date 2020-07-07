#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;

    std::vector<std::string> data(N, std::string(""));
    for (int k = 0; k < N; ++k) {
        std::cin >> data[k];
    }
    std::sort(data.begin(), data.end());

    for (int k = 0; k < N; ) {

        int counter{1};
        while ((k + counter) < N && data[k] == data[k + counter]) {
            ++counter;
        }
        if (counter > 1) std::cout << data[k] << std::endl;
        k += counter;
    }
    return 0;
}

// End of the file
