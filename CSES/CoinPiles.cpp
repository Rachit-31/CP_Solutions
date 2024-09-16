#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Check if the sum is divisible by 3 and neither pile is more than twice the size of the other
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
