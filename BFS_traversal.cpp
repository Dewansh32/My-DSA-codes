#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function (not inside any class)
vector<int> bfs(const vector<vector<int>>& adj) {
    queue<int> q;
    int size = adj.size();
    vector<bool> visited(size, false);
    vector<int> ans;

    // Start BFS from node 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // Visit all adjacent nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return ans;
}

int main() {
    int V = 5; // number of vertices

    // More detailed adjacency list (undirected graph)
    vector<vector<int>> adj(V);
    adj[0] = {1, 2, 3};
    adj[1] = {0, 4};
    adj[2] = {0, 3};
    adj[3] = {0, 2, 4};
    adj[4] = {1, 3};

    vector<int> result = bfs(adj);

    // Print BFS result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
