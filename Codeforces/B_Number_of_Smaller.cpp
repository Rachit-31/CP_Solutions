#include <bits/stdc++.h>
using namespace std;

#define int long long        
#define nl <<endl            
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vi ans(m);

    
    int i = 0;  
    for (int j = 0; j < m; j++) {  
        while (i < n && a[i] < b[j]) {
            i++;
        }
        ans[j] = i; 
    }


    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout  nl;
}

int32_t main() {
    fast_io();
    
   
    solve();
   
    return 0;
}
