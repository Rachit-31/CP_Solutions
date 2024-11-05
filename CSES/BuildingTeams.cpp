#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

bool bfs(int node, unordered_map<int, list<int>>& adj, vector<int>& team, vector<bool>& vis) {
    vis[node] = true;
    team[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int t = team[top];

        for (auto i : adj[top]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
                team[i] = (t == 1) ? 2 : 1;  
            } else if (team[i] == t) {
               
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> team(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!bfs(i, adj, team, vis)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
