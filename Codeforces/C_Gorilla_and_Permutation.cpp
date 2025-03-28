#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> perm;

    for (int i = n; i >= k; i--) {
        perm.push_back(i);
    }

    for (int i = m + 1; i < k; i++) {
        perm.push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        perm.push_back(i);
    }

    for (int num : perm) {
        cout << num << " ";
    }
    cout << '\n';
}

int32_t main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
