#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;  
    cin >> T;  // Number of test cases

    while (T--) {
        int n, m;
        cin >> n >> m;  // n: size of array, m: number of operations

        int max_val = 0;  // Initialize the maximum value

        // Read the array and find the initial maximum value
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            max_val = max(max_val, num);
        }

        // Process each operation
        for (int i = 0; i < m; i++) {
            char c;
            int l, r;
            cin >> c >> l >> r;

            // Only update the maximum value if it's within the range [l, r]
            if (l <= max_val && max_val <= r) {
                if (c == '+') {
                    max_val += 1;  // Increment the maximum value
                } else {
                    max_val -= 1;  // Decrement the maximum value
                }
            }

            // Output the current maximum value after the operation
            cout << max_val;
            if (i != m - 1) {
                cout << " ";  // Add space between outputs
            } else {
                cout << endl;  // Newline after the last output of the current test case
            }
        }
    }

    return 0;
}
