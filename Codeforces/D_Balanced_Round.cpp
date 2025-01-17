#include <bits/stdc++.h> 
using namespace std;

#define int long long        
#define endl '\n'            
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define all(v) v.begin(), v.end()


int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}

int lcm(int a, int b) { 
    return a / gcd(a, b) * b; 
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    
    sort(all(nums));

    int cnt = 1, ans = 1; 
    for (int i = 1; i < n; ++i) {
        if (nums[i] - nums[i - 1] > k) {
            cnt = 1;
        } else {
            ++cnt; 
        }
        ans = max(ans, cnt); 
    }

   
    cout << n - ans << '\n';
}

int32_t main() {
    fast_io();
    int t;  
    cin >> t;  
    while (t--) {
        solve(); 
    }
    return 0; 
}
