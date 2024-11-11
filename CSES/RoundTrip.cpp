#include <bits/stdc++.h>
using namespace std;

void findCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& parentNode, vector<bool>& visited, vector<int>& cycle) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parentNode[neighbor] = node;
            findCycle(neighbor, node, adj, parentNode, visited, cycle);
            if (!cycle.empty()) return; // Stop further DFS once the cycle is found
        } else if (neighbor != parent) {
            // Cycle detected
            int current = node;
            cycle.push_back(current);
            while (current != neighbor) {
                current = parentNode[current];
                cycle.push_back(current);
            }
            cycle.push_back(node); // Close the cycle
            reverse(cycle.begin(), cycle.end());
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parentNode(n + 1, -1);
    vector<bool> visited(n + 1, false);
    vector<int> cycle;

    // Try to find a cycle starting from each unvisited node
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            findCycle(i, -1, adj, parentNode, visited, cycle);
            if (!cycle.empty()) break; // Stop once a cycle is found
        }
    }

    if (cycle.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
