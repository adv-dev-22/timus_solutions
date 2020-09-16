#include <iostream>
#include <algorithm>

//int extract_uniform_block(const int * const a, const int length, int & k);


int main(int argc, char * argv [])
{
    // Data initialization.
    constexpr int N_max = 2000;
    int N = 0;
    long long P = 0;
    std::cin >> N >> P;

    long a[N_max];
    for (int i = 0; i < N; ++i) {std::cin >> a[i];}

    std::sort(a, a + N, std::less<int>());

    long coins[N_max];       // Nominal.
    long factors[N_max];     // Corresponding amount.
    long acc_factors[N_max]; // Accumulated factors.
    for (int i = 0; i < N; ++i) factors[i] = 1;

    // Compute coins and factors
    int index = 0;
    coins[index] = a[0];
    factors[index] = 1;
    for (int i = 1; i < N; ++i) {
        if (coins[index] == a[i]) {
            ++factors[index];
        } else {
            coins[++index] = a[i];
            factors[index] = 1;
        }
    }
    const int INDEX_MAX = index;

    // Compute damage and attempts
    long long coins_total = 0;
    long long attempts = 0;

    bool buffer_is_empty = true;
    long long coins_amount = 0;
    long buffer_coins_tot = 0;

    for (int ind = 0; ind <= INDEX_MAX; ++ind)
    {
        coins_amount += factors[ind];
        const long long damage = coins_amount * coins[ind];

        if (damage <= P)
        {
            buffer_coins_tot = coins_amount;
            buffer_is_empty = false;

            if (ind == INDEX_MAX) {
                coins_total += buffer_coins_tot;
                ++attempts;
            }
        }
        else if (damage > P)
        {
            if (!buffer_is_empty)
            {
                coins_total += buffer_coins_tot;
                ++attempts;

                coins_amount = 0;
                --ind;

                buffer_is_empty  = true;
                buffer_coins_tot = 0;
            } else {
                break;
            }
        }
    }

    std::cout << coins_total << " " << attempts << std::endl;

    // DEBUG
    //std::cout << "P = " << P << std::endl;
//    std::cout << "array:" << std::endl;
//    for (int i = 0; i < N; ++i) std::cout << a[i] << " ";
//    std::cout << std::endl;

//    std::cout << "coin nominals:" << std::endl;
//    for (int ind = 0; ind <= INDEX_MAX; ++ind) std::cout << coins[ind] << " ";
//    std::cout << std::endl;

//    std::cout << "coin factors:" << std::endl;
//    for (int ind = 0; ind <= INDEX_MAX; ++ind) std::cout << factors[ind] << " ";
//    std::cout << std::endl;

    return 0;
}

// End of the file
