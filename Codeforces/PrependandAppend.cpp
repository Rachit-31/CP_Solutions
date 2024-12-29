#include <iostream>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int s = 0, e = n - 1;

        
        while (s < e && str[s] != str[e]) {
            s++;
            e--;
        }

        
        cout <<(e - s + 1) << endl;
    }
}

int main() {
    solve();
    return 0;
}
