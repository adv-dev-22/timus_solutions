#include <iostream>

const int N_MAX = 201;

int main(int argc, char * argv [])
{
    // Data block
    int N = 0;

    // V --> M
    static int vm_01_in [N_MAX];
    static int vm_01_out[N_MAX];

    // M --> V
    static int mv_02_in [N_MAX];
    static int mv_02_out[N_MAX];

    // Read input
    std::cin >> N;
    for (int i = 0; i <= N; ++i)
    {
        vm_01_in [i] = 0;
        vm_01_out[i] = 0;

        mv_02_in [i] = 0;
        mv_02_out[i] = 0;
    }

    // In/out accumulations
    for (int i = 1; i <= N; ++i)
    {
        int a_ij;
        for (int j = 1; j < i; ++j)
        {
            std::cin >> a_ij;
            mv_02_in [i] += a_ij;
            mv_02_out[j] += a_ij;
        }
        std::cin >> a_ij;
        for (int j = i+1; j <= N; ++j)
        {
            std::cin >> a_ij;
            vm_01_in [i] += a_ij;
            vm_01_out[j] += a_ij;
        }
    }

    // V --> M current size
    int vm_01_max = 0;
    int vm_01_curr = 0;
    for (int k = 1; k <= N; ++k)
    {
        vm_01_curr += vm_01_in[k] - vm_01_out[k];
        if (vm_01_curr > vm_01_max) vm_01_max = vm_01_curr;
    }

    // M --> V current size
    int mv_02_max = 0;
    int mv_02_curr = 0;
    for (int k = N; k >= 1; --k)
    {
        mv_02_curr += mv_02_in[k] - mv_02_out[k];
        if (mv_02_curr > mv_02_max) mv_02_max = mv_02_curr;
    }

    // Final estimation
    const int capacity = 36;
    int cell_opt = std::max(vm_01_max, mv_02_max) / capacity;
    if (std::max(vm_01_max, mv_02_max) % capacity) ++cell_opt;

    std::cout << cell_opt << std::endl;

    return 0;
}

// End of the file
