#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 1;
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cout << ans << endl;
    return 0;
}