#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll pref_max = 0, s = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        pref_max = max(pref_max, (ll) a[i]);
        
        ll d = pref_max - a[i];
        s += d;
        mx = max(mx, d);
    }
    
    cout << s + mx << nl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}