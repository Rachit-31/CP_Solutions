#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl <<'\n'

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

   
    int min_recolor = k;  
    int current_whites = 0;

   
    for (int i = 0; i < k; i++) {
        if (s[i] == 'W') current_whites++;
    }

    min_recolor = current_whites;

  
    for (int i = k; i < n; i++) {
        if (s[i] == 'W') current_whites++;      
        if (s[i - k] == 'W') current_whites--;   
        
        min_recolor = min(min_recolor, current_whites);
    }

    cout << min_recolor << endl;
}

int32_t main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    // solve();
    return 0;
}
