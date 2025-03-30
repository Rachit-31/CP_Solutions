#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl <<'\n'           
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define in cin >>
#define out cout <<

void solve() {
    string a, b;
    in a;
    in b;

    int n = a.size(), m = b.size();
    int max_common = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = 0;
            while (i + len < n && j + len < m && a[i + len] == b[j + len]) {
                len++;
            }
            max_common = max(max_common, len);
        }
    }

    int result = (n - max_common) + (m - max_common);
    out result nl;
}

int32_t main() {
    fast_io();
    int t;  
    in t;  
    while (t--) {
        solve(); 
    }
    return 0; 
}
