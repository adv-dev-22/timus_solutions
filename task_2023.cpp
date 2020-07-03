#include <iostream>
#include <string>

int get_box_position(const std::string & s);

int main(int argc, char * argv []) {

    int n{0};
    std::cin >> n;

    int steps_numb  = 0;
    int current_pos = 1;

    for (int k = 0; k < n; ++k) {

        std::string str_buff;
        std::cin >> str_buff;

        const int box_pos = get_box_position(str_buff);

        steps_numb += std::abs(box_pos - current_pos);
        current_pos = box_pos;
    }

    std::cout << steps_numb << std::endl;

    return 0;
}

int get_box_position(const std::string & s_name) {

    if (s_name[0] == 'A' ||
        s_name[0] == 'P' ||
        s_name[0] == 'O' ||
        s_name[0] == 'R') return 1;

    if (s_name[0] == 'B' ||
        s_name[0] == 'M' ||
        s_name[0] == 'S') return 2;

    return 3;
}


// End of the file

