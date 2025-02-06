#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    string s, t;
    cin >> s >> t;

    int n1 = s.size(), n2 = t.size();
    int lcp_length = 0;

    while (lcp_length < min(n1, n2) && s[lcp_length] == t[lcp_length]) {
        lcp_length++;
    }

    int operations = lcp_length;  
    if (lcp_length > 0) operations++;  


    operations += (n1 - lcp_length) + (n2 - lcp_length);

    cout << operations << '\n';
}

int32_t main() {
    fast_io();
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
