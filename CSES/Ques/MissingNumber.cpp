#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a;
        m[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (m.find(i) == m.end()) {
            cout << i;
            break;
        }
    }
    return 0;
}
