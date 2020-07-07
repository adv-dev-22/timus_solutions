#include <iostream>
#include <vector>
#include <algorithm>

void encrease_position_if_exists(const int year_stud,
                                 std::vector<int> & ref_dates,
                                 int & counter) {

    auto found_item = std::lower_bound(ref_dates.begin(), ref_dates.end(), year_stud);

    if (found_item != ref_dates.end() && *found_item == year_stud) {
        counter++;
    }
}

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;
    std::vector<int> ref_dates;
    ref_dates.reserve(N);

    // Add first element
    int year_value;
    std::cin >> year_value;
    ref_dates.emplace_back(year_value);

    // Second and more
    for (int i = 1; i < N; ++i) {
        scanf("%d", &year_value);
        if (year_value > ref_dates.back()) {
            ref_dates.emplace_back(year_value);
        }
    }

    int M{0};
    std::cin >> M;

    int counter{0};

    for (int k = 0; k < M; ++k) {
        int year_stud{0};
        scanf("%d", &year_stud);
        encrease_position_if_exists(year_stud, ref_dates, counter);
    }
    std::cout << counter << std::endl;

    return 0;
}

// End of the file
