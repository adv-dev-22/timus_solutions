#include <iostream>
#include <vector>
#include <algorithm>

int main(int arc, char * argc []) {

    std::string buffer;
    std::getline(std::cin, buffer);
    int N = std::stoi(buffer);

    std::vector<std::string> data(N, std::string(""));
    for (int k = 0; k < N; ++k) {
        std::getline(std::cin, data[k]);
    }

    std::sort(data.begin(), data.end());

    int counter = 0;
    for (int i = 0; i + 1 < N; ) {

        int j{1};
        while (data[i] == data[i + j]) {
            counter++;
            j++;
        }
        i += j;
    }

    std::cout << counter << std::endl;
    return 0;
}


// End of the file
