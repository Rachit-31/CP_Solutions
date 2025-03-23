#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mn;

    for (int i = 0; i < n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            if (mn.find(i - j) == mn.end()) {
                mn[i - j] = a[j];
            } else {
                mn[i - j] = min(mn[i - j], a[j]);
            }
        }
    }

    int ans = 0;
    for (auto& [key, value] : mn) {
        if(value<0){
            ans += abs(value);
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
