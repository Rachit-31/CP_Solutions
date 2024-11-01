#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1); // adjacency list for 1-indexed cities
    
    // Reading the roads
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> representatives;

    // Find all disconnected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            representatives.push_back(i);  // Save a representative from each component
            dfs(i, adj, visited);
        }
    }

    // Minimum number of roads needed is (number of components - 1)
    int k = representatives.size() - 1;
    cout << k << endl;

    // Connect the components by connecting their representatives
    for (int i = 0; i < k; i++) {
        cout << representatives[i] << " " << representatives[i + 1] << endl;
    }

    return 0;
}
