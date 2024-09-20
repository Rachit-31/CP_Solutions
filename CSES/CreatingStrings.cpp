#include <bits/stdc++.h>
using namespace std;

void permutations(string str, vector<string>& ans, int start, int n) {
    if (start == n) {
        ans.push_back(str);  
        return;
    }
    
    for (int i = start; i < n; i++) {
        swap(str[start], str[i]);  
        permutations(str, ans, start + 1, n);  
        swap(str[start], str[i]);  
    }
}

void solve() {
    string str;
    cin >> str;
    int n = str.length();
    vector<string> ans;

    permutations(str, ans, 0, n);

    cout << ans.size() << endl;

    for (auto i : ans) {
        cout << i << endl;
    }

    return;
}

int main() {
    solve();
    return 0;
}