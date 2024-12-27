#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        } else if (k == 1) {
            cout << "NO" << endl;
        } else if (k == 2) {
            
            if (n % 2 == 0) {
                cout << "YES" << endl;
                cout << n / 2 << endl;
                for (int i = 0; i < n / 2; i++) {
                    cout << 2 << " ";
                }
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            // Case 4: k ≥ 3
            cout << "YES" << endl;
            if (n % 2 == 0) {
                // Even n
                cout << n / 2 << endl;
                for (int i = 0; i < n / 2; i++) {
                    cout << 2 << " ";
                }
                cout << endl;
            } else {
                // Odd n
                cout << n / 2 << endl;
                cout << 3 << " ";
                for (int i = 0; i < n / 2 - 1; i++) {
                    cout << 2 << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
