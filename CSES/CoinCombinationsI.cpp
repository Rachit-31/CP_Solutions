#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define endl '\n'            

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define vi vector<int>

const int MOD = 1e9 + 7;

int32_t main() {
    fast_io();
    int n, x;
    cin >> n >> x;
    vi coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    
    vi dp(x + 1, 0);
    dp[0] = 1;  


    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}
