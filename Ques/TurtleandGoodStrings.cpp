#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 110;  // Maximum size of the string

int n;
char s[maxn];

void solve() {
    cin >> n >> s;  // Read the integer n and the string s (0-indexed)

    // Check if the first character is different from the last character
    if (s[0] != s[n - 1]) {  // Adjusted to 0-indexing
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int T;  // Number of test cases
    cin >> T;

    while (T--) {
        solve();  // Solve each test case
    }

    return 0;
}
