#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int cnt0 = 0, cnt1 = 0; 

    
    for (char c : s) {
        if (c == '0')
            cnt0++;
        else
            cnt1++;
    }

 
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || (s[i] == '0' && cnt1 == 0) || (s[i] == '1' && cnt0 == 0)) {
            cout << s.length() - i << endl;
            break;
        }
        if (s[i] == '0') 
            cnt1--;
        else 
            cnt0--;
    }
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        solve();
    }

    return 0;
}
