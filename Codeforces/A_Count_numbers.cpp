#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    unordered_map<int, int> freq; // Store occurrences of numbers

    while (q--) {
        int z, x;
        cin >> z >> x;
        
        if (z == 1) {
            freq[x]++; // Increment frequency count
        } else if (z == 2) {
            cout << freq[x] << '\n'; // Print occurrences of x
        }
    }

    return 0;
}
