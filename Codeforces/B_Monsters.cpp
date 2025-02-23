#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl <<'\n'           
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define pii pair<int, int>

#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb push_back

void printi(vi &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    vector<pii> order;  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int rem = a[i] % k;
        if (rem == 0) rem = k; 
        order.pb({rem, i});
    }

    
    stable_sort(all(order), [&](const pii &p1, const pii &p2) {
        return p1.first > p2.first;
    });    

    vi ans;
    for (auto &i : order) {
        int rem = i.first;
        int idx = i.second;
        ans.pb(idx + 1);  
    }

    printi(ans);
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