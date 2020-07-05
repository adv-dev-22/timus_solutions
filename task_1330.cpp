#include <iostream>
#include <vector>
#include <cmath>

void build_segment_tree(const int n_base, std::vector<int> & st);

int  sum_segment_tree(const int q1, const int q2,
                      const int vertex_range_left, const int vertex_range_right, const int vertex_index,
                      const std::vector<int> & st);

int main(int argc, char * argv []) {

    int N = 0;
    scanf("%d", &N);

    int power_2_ceiled = ceil(log(static_cast<double>(N)) / log(2.0));
    int n_base = pow(2.0, power_2_ceiled);

    std::vector<int> st(2 * n_base, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &st[n_base + i]); // n_base is always even (power of 2)
    }
    // Now leafs are initialized.
    // So, we can
    build_segment_tree(n_base, st);

    int Q = 0;
    scanf("%d", &Q);
    for (int k = 0; k < Q; ++k) {

        int q1, q2;
        scanf("%d%d", &q1, &q2);

        printf("%d\n", sum_segment_tree(q1 - 1, q2 - 1, 0, n_base - 1, 1, st));
    }

    return 0;
}

void build_segment_tree(const int n_base, std::vector<int> & st) {

    for (int j = n_base - 1; j > 0; --j) {
        st[j] = st[2 * j] + st[2 * j + 1];
    }
}

int sum_segment_tree(const int q1, const int q2,
                     const int vertex_range_left, const int vertex_range_right, const int vertex_index,
                     const std::vector<int> & st) {

    if (q2 < vertex_range_left || vertex_range_right < q1) {
        // Range [q1,q2] is completely outside the vertex vertex_index.
        return 0;
    }

    if (q1 <= vertex_range_left && vertex_range_right <= q2) {
        // Range corresponds exactly to the vertex range.
        return st[vertex_index];
    }

    const int vertex_range_mid = (vertex_range_left + vertex_range_right) /2;

    const int left_sub_sum  = sum_segment_tree(q1, q2, vertex_range_left, vertex_range_mid,
                                               2 * vertex_index, st);

    const int right_sub_sum = sum_segment_tree(q1, q2, vertex_range_mid + 1, vertex_range_right,
                                               2 * vertex_index + 1, st);
    return left_sub_sum + right_sub_sum;
}

// End of the file
