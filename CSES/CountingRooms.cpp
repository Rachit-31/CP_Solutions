#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<char>>& mpp, vector<vector<bool>>& vis, int i, int j) {
    int r = mpp.size();
    int c = mpp[0].size();

    stack<pair<int, int>> s;
    s.push({i, j});
    vis[i][j] = true;

    while (!s.empty()) {
        pair<int, int> top = s.top();
        int x = top.first;
        int y = top.second;
        s.pop();

   
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny] && mpp[nx][ny] == '.') {
                vis[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}

void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> mpp(r, vector<char>(c));
    vector<vector<bool>> vis(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mpp[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j] && mpp[i][j] == '.') {  
                dfs(mpp, vis, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
