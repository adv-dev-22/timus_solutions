#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>

const int n_max = 101;

int main(int argc, char * argv [])
{
    std::set<std::string> names_set;
    std::string team[n_max][3];

    std::unordered_map<std::string, int> umap_names_idx;
    std::vector<std::set<int>> graph;

    // Input
    int N = 0;
    std::cin >> N;
    std::string buffer;
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            std::cin >> buffer;
            names_set.insert(buffer);
            team[i][k] = buffer;
        }
    }

    // Distances initialization
    std::vector<int>  distance(names_set.size(), -1);
    std::vector<bool> visited(names_set.size(), false);

    // Hashes
    auto itr = names_set.begin();
    for (int k = 0; itr != names_set.end(); ++itr)
    {
        auto xp = std::make_pair(*itr, k++);
        umap_names_idx.insert(xp);
    }

    graph.resize(umap_names_idx.size());

    // Build graph
    for (int i = 0; i < N; ++i)
    {
        int j = 0;
        for (int j = 0; j < 3; ++j)
        {
            const int idx = umap_names_idx[team[i][j]];
            graph[idx].insert(umap_names_idx[team[i][(j + 1) % 3]]);
            graph[idx].insert(umap_names_idx[team[i][(j + 2) % 3]]);
        }
    }

    // BFS
    const std::string start_node("Isenbaev");
    std::queue<int> nodes_queue;

    auto isen_itr = umap_names_idx.find(start_node);
    if (umap_names_idx.end() != isen_itr)
    {
        const int isen_idx = isen_itr->second;
        nodes_queue.push(isen_idx);
        visited[isen_idx] = true;
        distance[isen_idx] = 0;

        while (!nodes_queue.empty())
        {
            int node = nodes_queue.front();
            nodes_queue.pop();

            for (auto item : graph.at(node))
            {
                if (!visited[item])
                {
                    nodes_queue.push(item);
                    visited[item] = true;
                    distance[item] = distance[node] + 1;
                }
            }
        }
    }

    // Print
    int k = 0;
    for (auto itr = names_set.begin(); itr != names_set.end(); ++itr, ++k)
    {
        int dist = distance[k];
        if (dist >= 0) {
            std::cout << *itr << " " << dist << std::endl;
        }
        else
        {
            std::cout << *itr << " " << "undefined" << std::endl;
        }
    }

    return 0;
}

// End of the file
