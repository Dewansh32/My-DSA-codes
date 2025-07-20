#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited)
    {
        visited[node] = 1;
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
            {
                DFS(adj[node][i], adj, ans, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, 0);
        DFS(0, adj, ans, visited);
        return ans;
    }
};

// Driver code (you can modify for custom input)
int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    
    // Example graph (undirected or directed)
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0};
    adj[3] = {0, 4};
    adj[4] = {3};

    Solution obj;
    vector<int> res = obj.dfs(adj);

    // Output the DFS traversal
    for(int node : res) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
