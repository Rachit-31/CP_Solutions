#include <bits/stdc++.h>
using namespace std;

#define nl <<'\n'
#define in cin >>
#define out cout <<

void solve() {
    int n;
    in n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) in a[i];

    sort(a.begin(), a.end()); 

    int max_even_sum = -1; 

    
    for (int i = n - 1; i > 0; i--) {  
        for (int j = i - 1; j >= 0; j--) {  
            int sum = a[i] + a[j];
            if (sum % 2 == 0) {  
                max_even_sum = max(max_even_sum, sum);
                break; 
            }
        }
    }

    out max_even_sum nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
