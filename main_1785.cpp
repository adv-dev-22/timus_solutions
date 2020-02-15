#include <iostream>
#include <vector>

using  std::cout;
using  std::endl;

int main(int argc, char * argv []) {

    std::vector<size_t> index = {1,5,10,20,50,100,250,500,1000};
    std::vector<std::string> values = {"few", "several", "pack", "lots", "horde",
                                      "throng", "swarm", "zounds", "legion"};
    size_t a;
    std::cin >> a;

//for (size_t a = 1; a <=2000; ++a) {
    size_t l = 0;
    size_t r = 8;
    size_t i = (r + l) / 2;

    if (a >= index[r]) i = r;
    else {
        while (r > l+1) {

            if (index[i] <= a) l = i;
            if (index[i] >  a) r = i;

            i = (r + l) / 2;
        }
    }
//    cout << index[i] << " <-- " << a << endl;
//}

    std::cout << values[i] << std::endl;

    return 0;
}
