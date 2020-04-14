#include <iostream>
#include <string>

using  std::cout;
using  std::endl;

int main(int argc, char * argv []) {

    const std::string plus_one("+one");

    int n;
    std::cin >> n;

    std::string name;
    int counter = 0;
    for (int i = 0; i < n; ++i) {

        std::cin >> name;
        ++counter;

        if (name.length() > 4)
            if (std::string::npos != name.find(plus_one, name.length() - 4))
                ++counter;
    }

    if (11 == counter) ++counter;

    counter += 2;

    std::cout << counter * 100 << std::endl;

    return 0;
}



// End of the file

