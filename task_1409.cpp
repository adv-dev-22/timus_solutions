#include <iostream>

int main(int argc, char * argv []) {

    int a_ga = 0;
    int b_la = 0;

    std::cin >> a_ga >> b_la;

    const int jars_tot = a_ga + b_la - 1;
    const int rest_ga = jars_tot - a_ga;
    const int rest_la = jars_tot - b_la;

    std::cout << rest_ga << " " << rest_la << std::endl;

    return 0;
}
