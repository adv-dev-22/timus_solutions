#include <iostream>
#include <map>
#include <queue>

void insert(const int value, std::map<int, int> & wrk_map);
void remove(const int value, std::map<int, int> & wrk_map);

int main(int argc, char * argv []) {

    std::map<int, int> M_map;
    std::queue<int> M_queue;

    int M = 0;
    std::cin >> M;

    int temp = 0;

    // Initialization of the initial M-block;
    for (int k = 0; k < M; ++k) {

        std::cin >> temp;

        // Add current value into the queue
        M_queue.push(temp);

        // Add current value into the map
        insert(temp, M_map);
    }

    do {
        std::cout << M_map.crbegin()->first << std::endl;
        std::cin >> temp;

        const int rmv_value = M_queue.front();
        M_queue.pop();
        M_queue.push(temp);

        insert(temp, M_map);
        remove(rmv_value, M_map);

    } while (-1 != temp);

    return 0;
}

void insert(const int value, std::map<int, int> & wrk_map) {

    auto itr = wrk_map.find(value);
    if (wrk_map.end() != itr) {
        itr->second++;
    } else {
        wrk_map.insert(std::pair<int, int>(value, 1));
    }
}

void remove(const int value, std::map<int, int> & wrk_map) {

    auto itr = wrk_map.find(value);
    if (wrk_map.end() != itr) {
        if (itr->second > 1) {
            itr->second--;
        } else {
            wrk_map.erase(itr);
        }
    }
}

// End of the file
