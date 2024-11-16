#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18

void solve() {
    int n, m; 
    cin >> n >> m;

    // Adjacency list for the graph
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // Directed graph
    }

    // Distance array
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    // Min-heap priority queue (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto top = pq.top();
        int currDist = top.first;
        int node = top.second;
        pq.pop();

        // Skip if we've already found a shorter path
        if (currDist > dist[node]) continue;

        for (auto top : adj[node]) {
            int neighbor = top.first;
            int weight = top.second;
            if (currDist + weight < dist[neighbor]) {
                dist[neighbor] = currDist + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Output the shortest distances
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
