#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

void solve() {
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    
    for (char c : s) {
        freq[c]++;
    }

    int cnt1 = 0, cnt2 = 0;

    for (auto &i : freq) {
        int count = i.second;
        if (count == 1) {
            cnt1++;  
        } else {
            cnt2++;  
        }
    }
    cout << (cnt2 + cnt1 / 2) << nl;
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
