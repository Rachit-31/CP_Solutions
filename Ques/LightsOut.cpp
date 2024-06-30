#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int newx, int newy, int n){
    return newx >= 0 && newx < n && newy >= 0 && newy < n;
}

void toggle(vector<vector<bool>>& ans, int r, int c, int n) {
    ans[r][c] = !ans[r][c];
    if (isPossible(r + 1, c, n)) ans[r + 1][c] = !ans[r + 1][c];
    if (isPossible(r - 1, c, n)) ans[r - 1][c] = !ans[r - 1][c];
    if (isPossible(r, c + 1, n)) ans[r][c + 1] = !ans[r][c + 1];
    if (isPossible(r, c - 1, n)) ans[r][c - 1] = !ans[r][c - 1];
}

void solve(vector<vector<int>>& lights, vector<vector<bool>>& ans, int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (lights[r][c] % 2 != 0) {
                toggle(ans, r, c, n);
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<int>> lights(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> lights[i][j];
        }
    }

    vector<vector<bool>> ans(n, vector<bool>(n, true));
    solve(lights, ans, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
