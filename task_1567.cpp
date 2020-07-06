#include <iostream>
#include <string>

int get_cost_value(const char ch) {

    if (ch == ' ') return 1;
    if (ch == '.') return 1;
    if (ch == ',') return 2;
    if (ch == '!') return 3;

    int diff_ch = ch - 'a';
    return diff_ch % 3 + 1;
}

int main(int argc, char * argv []) {

    std::string s1;
    std::getline(std::cin, s1);

    int counter{0};
    for (auto item : s1) {
        counter += get_cost_value(item);
    }
    std::cout << counter << std::endl;

    return  0;
}



// End of the file
