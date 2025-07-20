#include<iostream>
#include<vector>
using namespace std;

int main() {
    int vertex, edges;
    cout << "Enter number of vertices: ";
    cin >> vertex;
    cout << endl;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << endl;

    // Choose graph type
    int graphType;
    cout << "Choose graph type:" << endl;
    cout << "1. Undirected Unweighted" << endl;
    cout << "2. Directed Unweighted" << endl;
    cout << "3. Undirected Weighted" << endl;
    cout << "4. Directed Weighted" << endl;
    cout << "Enter choice (1-4): ";
    cin >> graphType;
    cout << endl;

    if (graphType == 1) {
        // **UNDIRECTED UNWEIGHTED GRAPH**
        cout << "=== Undirected Unweighted Graph ===" << endl;
        vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
        
        int u, v;
        cout << "Enter edges (u v):" << endl;
        for(int i = 0; i < edges; i++) {
            cin >> u >> v;
            AdjMat[u][v] = 1;
            AdjMat[v][u] = 1;  // Both directions for undirected
        }
        
        cout << "Adjacency Matrix:" << endl;
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (graphType == 2) {
        // **DIRECTED UNWEIGHTED GRAPH**
        cout << "=== Directed Unweighted Graph ===" << endl;
        vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
        
        int u, v;
        cout << "Enter edges (u v):" << endl;
        for(int i = 0; i < edges; i++) {
            cin >> u >> v;
            AdjMat[u][v] = 1;  // Only one direction for directed
        }
        
        cout << "Adjacency Matrix:" << endl;
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (graphType == 3) {
        // **UNDIRECTED WEIGHTED GRAPH**
        cout << "=== Undirected Weighted Graph ===" << endl;
        vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));
        
        int u, v, weight;
        cout << "Enter edges with weights (u v weight):" << endl;
        for(int i = 0; i < edges; i++) {
            cin >> u >> v >> weight;
            AdjMat[u][v] = weight;
            AdjMat[v][u] = weight;  // Both directions with same weight
        }
        
        cout << "Adjacency Matrix:" << endl;
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (graphType == 4) {
        // **DIRECTED WEIGHTED GRAPH**
        cout << "=== Directed Weighted Graph ===" << endl;
        vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));
        
        int u, v, weight;
        cout << "Enter edges with weights (u v weight):" << endl;
        for(int i = 0; i < edges; i++) {
            cin >> u >> v >> weight;
            AdjMat[u][v] = weight;  // Only one direction with weight
        }
        
        cout << "Adjacency Matrix:" << endl;
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
