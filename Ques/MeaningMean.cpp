#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array in ascending order
    sort(a.begin(), a.end());

    // Simulate the merging process
    int result = a[0];
    
    for (int i = 1; i < n; i++) {
        result = (result + a[i]) / 2;  // Floor of the average is automatically handled by integer division
    }

    // Output the result for this test case
    cout << result << endl;
}

int main() {
    fast_io();  // Enable fast I/O
    
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        solve(); 
    }

    return 0;
}
