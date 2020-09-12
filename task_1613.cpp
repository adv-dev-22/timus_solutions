#include <cstdio>
#include <map>
#include <set>
#include <cstddef>

int main(int argc, char * argv []) {

    int N;
    scanf("%d", &N);

    // amount, town_idx
    std::map<size_t, std::set<size_t>> amount_map;

    for (int k = 0; k < N; ++k) {
        int value;
        scanf("%d", &value);

        auto itr = amount_map.insert(std::pair<size_t, std::set<size_t>>(value, std::set<size_t>()));
        itr.first->second.insert(k + 1);
    }

    int Q;
    scanf("%d", &Q);
    for (size_t k = 0; k < Q; ++k) {

        size_t l, r, value;


    }

    //printf("%d", N);


    return 0;
}

// End of the file
