#include <iostream>

void setup_member(int * const m, int * const x);

int main(int argc, char * argv[]) {

    constexpr size_t K = 3;
    constexpr size_t N = 4000;

    int a[K][N];
    int idx[K];
    int current_idx[K];

    int size[K];

    for (int k = 0; k < K; ++k) {
        setup_member(&size[k], a[k]);
        idx[k] = 0;
        current_idx[k] = 0;
    }

    int capture_number = 0;

    for (idx[0] = 0; idx[0] < size[0]; ++idx[0]) {

        if (a[0][idx[0]] < a[1][current_idx[1]]) continue;

        for (idx[1] = current_idx[1]; idx[1] < size[1]; ++idx[1]) {

            if (a[1][idx[1]] > a[0][idx[0]]) {
                current_idx[1] = idx[1];
                break;
            }

            if (a[1][idx[1]] == a[0][idx[0]]) {

                current_idx[1] = idx[1] + 1;

                for (idx[2] = current_idx[2]; idx[2] < size[2]; ++idx[2]) {

                    if (a[2][idx[2]] > a[1][idx[1]]) {
                        current_idx[2] = idx[2];
                        break;
                    }

                    if (a[2][idx[2]] == a[1][idx[1]]) {
                        ++capture_number;
                        current_idx[2] = idx[2] + 1;
                        break;
                    }
                }
                break;
            }
        }
    }

    std::cout << capture_number << std::endl;

    return 0;
}

void setup_member(int * const m, int * const x) {

    std::cin >> *m;
    for (int k = 0; k < *m; ++k) {
        std::cin >> x[k];
    }
}

// End of the file




//    bool any_array_not_end = true;
//    do {
//        // Find next global maximum
//        int glob_max = a[0][index[0]];
//        for (int k = 1; k < K; ++k) {
//            if (glob_max < a[k][index[k]]) glob_max = a[k][index[k]];
//        }
//        std::cout << "glob_max = " << glob_max << std::endl;

//        for (int k = 0; k < K; ++k) {
//            while ((a[k][index[k]] < glob_max) && (index[k] + 1 < size[k])) {
//                ++index[k];
//            }
//            std::cout << index[k] << " ";
//        }
//        std::cout << std::endl;

//        bool capture_flag = true;
//        int tmp_ind = index[0];
//        for (int k = 1; k < K; ++k) {
//            if (a[0][tmp_ind] != a[k][index[k]]) {
//                capture_flag = false;
//                break;
//            }
//        }
//        std::cout << "capture_flag = " << capture_flag << std::endl;

//        if (capture_flag) {
//            ++capture_number;
//            for (int k = 0; k < K; ++k) {
//                std::cout << " " << a[k][index[k]];
//                ++index[k];
//            }
//        }
//        std::cout << std::endl;

//        for (int k = 0; k < K; ++k) {
//            if (index[k] + 1 >= size[k] && !capture_flag) any_array_not_end = false;
//        }

//    } while (any_array_not_end);
