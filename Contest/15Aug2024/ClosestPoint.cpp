#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        // Check the minimum gap between consecutive points
        int min_gap = INT_MAX;
        for (int i = 1; i < n; i++) {
            min_gap = min(min_gap, nums[i] - nums[i-1]);
        }

        // If the minimum gap is greater than 1, we can insert a new point
        if (min_gap > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
