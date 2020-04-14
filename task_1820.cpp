#include <iostream>


int main(int argc, char * argv []) {

    int n;
    int k;

    std::cin >> n >> k;

    int T = 2;

    int addit = 0;
    int tail = n % k;

    if (2 * tail > k) ++addit;
    if (tail) ++addit;

    if (n > k) T = 2 * (n / k) + addit;

    std::cout << T << std::endl;

    return 0;
}




// End of the file
