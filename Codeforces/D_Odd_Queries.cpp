#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int t;
    cin >> t; 

    while (t--) {
        int n, q;
        cin >> n >> q; 
        vector<ll> a(n + 1); 
        ll total_sum = 0;

       
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total_sum += a[i];
        }

        
        vector<ll> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        }

        while (q--) {
            int l, r;
            ll k;
            cin >> l >> r >> k;

           
            ll range_sum = prefix_sum[r] - prefix_sum[l - 1];

            
            ll new_sum = total_sum - range_sum + (r - l + 1) * k;

            
            if (new_sum % 2 == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
int main(){
    solve();
    return 0;
}