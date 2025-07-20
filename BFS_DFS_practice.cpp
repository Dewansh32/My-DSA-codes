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

void DFS(int node,vector<vector<int>> &adj,vector<bool> visited,vector<int> ans)
{
    visited[node] = true;
    ans.push_back(node);

    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            DFS(adj[node][i],adj,visited,ans);
        }
    }
}


vector<int> dfs(vector<vector<int>> &adj)
{
    int size = adj.size();
    vector<bool> visited(size,0);
    vector<int> ans;

    DFS(0,adj,visited,ans);

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
    vector<int> res = dfs(adj);

    // Print BFS result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
