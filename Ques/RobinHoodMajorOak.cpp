#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // If k == 1, only leaves from year n matter
        if (k == 1) {
            if (n % 2 == 0) {
                cout << "YES" << endl;  // Even number of leaves in year n
            } else {
                cout << "NO" << endl;   // Odd number of leaves in year n
            }
        } else {
            // Sum of consecutive integers from n-k+1 to n
            long long start = n - k + 1;
            long long sum = (start + n) * k / 2;  
            
            if (sum % 2 == 0) {
                cout << "YES" << endl;  
            } else {
                cout << "NO" << endl;   
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
