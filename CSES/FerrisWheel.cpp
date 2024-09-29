#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // Sort the weights
    sort(weights.begin(), weights.end());

    int i = 0, j = n - 1;
    int gondolas = 0;

    while (i <= j) {
        
        if (weights[i] + weights[j] <= x) {
            i++; 
        }
       
        j--;
        gondolas++; 
    }

    cout << gondolas << endl;
}

int main() {
    solve();
    return 0;
}
