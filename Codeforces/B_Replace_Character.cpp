#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl <<'\n'           
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> freq;

    
    for (char c : s) {
        freq[c]++;
    }

    
    char min_char = 'z' + 1, max_char = 'a' - 1;
    int min_freq = INT_MAX, max_freq = 0;

    for (auto i : freq) {
        int f = i.second;
        char ch = i.first;
        
        if (f < min_freq || (f == min_freq && ch < min_char)) {
            min_freq = f;
            min_char = ch;
        }

      
        if (f > max_freq || (f == max_freq && ch > max_char)) {
            max_freq = f;
            max_char = ch;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == min_char) {
            s[i] = max_char;
            break; 
        }
    }

    cout << s << '\n';
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
