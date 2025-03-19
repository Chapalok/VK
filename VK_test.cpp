#include <iostream>
#include <queue>
#include <vector>

void Bfs(const std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& dist, int64_t start) {
    dist.resize(graph.size(), -1);
    dist[start] = 0;

    std::queue<int64_t> q;
    q.push(start);
    while (!q.empty()) {
        int64_t cur_node = q.front();
        q.pop();

        for (const auto& neighbour : graph[cur_node]) {
            if (dist[neighbour] == -1) {
                dist[neighbour] = dist[cur_node] + 1;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    int64_t cnt_vertex;
    int64_t cnt_edges;
    std::cin >> cnt_vertex >> cnt_edges;

    std::vector<std::vector<int64_t> > graph(cnt_vertex);
    int64_t from;
    int64_t to;
    for (int64_t i = 0; i < cnt_edges; ++i) {
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int64_t start;
    std::cin >> start;
    std::vector<int64_t> dist;
    Bfs(graph, dist, start);

    for (int64_t i = 0; i < cnt_vertex; ++i) {
        std::cout << dist[i] << "\n";
    }
}
