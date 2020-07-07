#include <iostream>
#include <vector>
#include <algorithm>

bool Comparator(const std::pair<int, int> & item1,
                const std::pair<int, int> & item2) {
    return item1.first < item2.first;
}

void encrease_position_if_exists(const int year_stud,
                                 std::vector<std::pair<int, int>> & ref_dates,
                                 int & counter) {

    auto found_item = std::lower_bound(ref_dates.begin(), ref_dates.end(),
                                       std::pair<int, int>(year_stud, 0),
                                       Comparator);

//    std::cout << "inp_year = " << year_stud << std::endl;

    if (found_item != ref_dates.end() && found_item->first == year_stud) {
//        if (0 == found_item->second) {
//            found_item->second++;
            counter++;
            //std::cout << " !!!!  " << std::endl;
//        }
    }
}

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;
    std::vector<std::pair<int, int>> ref_dates;
    ref_dates.reserve(N);

    // Add first element
    int year_value;
    std::cin >> year_value;
    ref_dates.emplace_back(std::pair<int, int>(year_value, 0));

    // Second and more
    for (int i = 1; i < N; ++i) {
        std::cin >> year_value;
        if (year_value > ref_dates.back().first) {
            ref_dates.emplace_back(std::pair<int, int>(year_value, 0));
        }
    }

//    for (auto & item : ref_dates) {
//        std::cout << item.first << " " << item.second << std::endl;
//    }

    int M{0};
    std::cin >> M;

    int counter{0};

    for (int k = 0; k < M; ++k) {

        int year_stud{0};
        std::cin >> year_stud;

        encrease_position_if_exists(year_stud, ref_dates, counter);
    }

    std::cout << counter << std::endl;

    return 0;
}

// End of the file
