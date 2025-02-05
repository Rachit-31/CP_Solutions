#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl '\n'           
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());  
    int left = 0, right = n - 1;
    int score = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            score++;
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    cout << score << nl;  
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
