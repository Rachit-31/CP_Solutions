#include <iostream>
#include <vector>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        // Check if the required conditions for existence are met
        if (s < k * b || s > k * b + (k - 1) * n) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(n, 0);
        a[0] = k * b;  // Assign k*b to the first element
        s -= k * b;    // Reduce s by this assigned value

        // Distribute remaining sum among elements
        for (int i = 0; i < n && s > 0; ++i) {
            int add = min(s, k - 1);  // We can add at most (k-1) to each element
            a[i] += add;
            s -= add;
        }

        // Print the result
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
