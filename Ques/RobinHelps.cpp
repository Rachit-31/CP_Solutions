#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define endl '\n'            
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int currGold = 0;  
    int giveCount = 0;  

    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            currGold += a[i]; 
        } 
        else if (a[i] == 0 && currGold > 0) {
            currGold--;  
            giveCount++;  
        }
    }

    cout << giveCount << endl;  
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
