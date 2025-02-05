#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout << x << '\n', 0;
using namespace std;

int Main() {
    ll n, k;
    cin >> k >> n; 

    vector<ll> a(n * k + 1); 
    for (int i = 1; i <= n * k; i++) {
        cin >> a[i];
    }

    ll x = (k + 1) / 2 - 1;
    x = k - x;
    ll z = n * k + 1;
    ll ans = 0;

    while (n--) {
        z -= x;
        if (z <= 0) break;  
        ans += a[z];
    }

    cout << ans << endl;
    return 0;  
}

int32_t main() {
    sync;
    ll t;
    cin >> t;
    while (t--) {
        Main();
    }
}
