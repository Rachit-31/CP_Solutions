#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<bool> present(2 * M + 1, false); 

    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        present[ai + M] = true; 
    }

 
    for (int x = -M; x <= M; x++) {
        if (!present[x + M]) {
            cout << x << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
