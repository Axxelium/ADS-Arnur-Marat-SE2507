#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adj;

public:
    Graph(int v) : vertices(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Breadth-First Search: O(V + E)
    void bfs(int start) const {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        std::cout << "BFS from " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }

    // Depth-First Search: O(V + E)
    void dfs(int start) const {
        std::vector<bool> visited(vertices, false);
        std::cout << "DFS from " << start << ": ";
        dfsHelper(start, visited);
        std::cout << "\n";
    }

private:
    void dfsHelper(int node, std::vector<bool>& visited) const {
        visited[node] = true;
        std::cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.bfs(0);
    g.dfs(0);

    return 0;
}
