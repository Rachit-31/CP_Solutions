#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countArraysBottomUp(int n, int m, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // Initialize the first row
    if (arr[0] != 0) {
        dp[0][arr[0]] = 1; // If the first element is fixed
    } else {
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1; // If the first element is unknown
        }
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int x = 1; x <= m; x++) {
            if (arr[i] != 0 && arr[i] != x) continue; // Skip invalid cases
            int count = 0;
            if (x > 1) count = (count + dp[i - 1][x - 1]) % MOD; // Transition from x - 1
            count = (count + dp[i - 1][x]) % MOD;                 // Transition from x
            if (x < m) count = (count + dp[i - 1][x + 1]) % MOD; // Transition from x + 1
            dp[i][x] = count;
        }
    }

    // Sum up all valid arrays ending at the last index
    int result = 0;
    if (arr[n - 1] != 0) {
        result = dp[n - 1][arr[n - 1]];
    } else {
        for (int x = 1; x <= m; x++) {
            result = (result + dp[n - 1][x]) % MOD;
        }
    }

    return result;
}
int main(){
    int n, m;
    cin>>n;
    cin>>m;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<countArraysBottomUp(n,m, nums)<<endl;
    return 0;
}