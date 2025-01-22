#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>

const int INF = 1e18;  
const int MOD = 1e9 + 7;

int solve(int n, vi &dp) {
    if (n == 0) return 0;  
    if (dp[n] != -1) return dp[n];  
    int steps = INF;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;  
        temp /= 10;
        if (digit > 0) {
            steps = min(steps, 1 + solve(n - digit, dp));  
        }
    }

    return dp[n] = steps;  
}

int32_t main() {
    int n;
    cin >> n;

    vi dp(n + 1, -1);  
    cout << solve(n, dp) << endl;

    return 0;
}
