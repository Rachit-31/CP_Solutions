#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

void solve() {
    int n;
    cin >> n;

    int x = 1;
    while (n % x == 0) {
        x++;
    }

    cout << x - 1 << nl;
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
