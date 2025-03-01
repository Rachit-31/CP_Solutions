#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl '\n'           
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

void solve() {
    int n, r, b;
    cin >> n >> r >> b;

    int group_size = r / (b + 1);  
    int extra = r % (b + 1);     

    string ans;
    
    for (int i = 0; i < b + 1; i++) {
        
        for (int j = 0; j < group_size; j++) {
            ans += 'R';
        }
        
        if (extra > 0) {
            ans += 'R';
            extra--;
        }
       
        if (i < b) {
            ans += 'B';
        }
    }

    cout << ans << nl;
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
