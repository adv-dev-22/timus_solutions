#include <iostream>
#include <vector>

int main(int argc, char * argv []) {

    int N{0};
    std::cin >> N;

    std::vector<int> arr(N * N, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> arr[i * N + j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int s = 0; s <= k; ++s) {
            const int i_diag = k - s;
            const int j_diag = s;
            std::cout << arr[i_diag * N + j_diag] << " ";
        }
    }
    for (int k = 1; k < N; ++k) {
        for (int s = k; s < N; ++s) {
            const int i_diag = N - s + k - 1;
            const int j_diag = s;
            std::cout << arr[i_diag * N + j_diag] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

// End of the file
