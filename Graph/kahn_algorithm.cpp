#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

std::pair<std::vector<int>, std::string> kahnTopologicalSort(std::vector<std::vector<int>> &edges) {
    std::queue<int> q;
    std::vector<int> topologicalArr;
    std::unordered_map<int, int> vertex2inDegree;
    std::unordered_map<int, std::vector<int>> vertex2next;

    // Initialize `Vertex2inDegree` and `vertex2next`
    for (int i=0; i<edges.size(); ++i) {
        int v = edges[i][0];
        int u = edges[i][1];
        ++vertex2inDegree[u];
        vertex2next[v].emplace_back(u);
    }

    // Initialize queue
    for (auto &[ v, indegree ]: vertex2inDegree) {
        if (indegree == 0) {
            q.push(v);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topologicalArr.emplace_back(v);

        for (int &u: vertex2next[v]) {
            --vertex2inDegree[u];

            if (vertex2inDegree[u] == 0) {
                q.push(u);
            }
        }
    }

    std::string msg = "There is no cycle.";
    if (topologicalArr.size() < vertex2inDegree.size()) {
        msg = "There is a cycle.";
    }

    return {topologicalArr, msg};
}


int main() {
    std::vector<std::vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4},
        {4, 2}
    };

    auto [topologicalArr, msg] = kahnTopologicalSort(edges);

    std::cout << msg << std::endl;

    return 0;
}