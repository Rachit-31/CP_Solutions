#include <iostream>
#include <vector>
using namespace std;

int minSnaps(vector<int>& a) {
    int n = a.size();
    bool allZero = true;  
    int left = -1, right = -1;

    
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (left == -1) left = i; 
            right = i;                
            allZero = false;          
        }
    }

   
    if (allZero) return 0;

    
    for (int i = left; i <= right; i++) {
        if (a[i] == 0) return 2; 
    }

   
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << minSnaps(a) << "\n";
    }

    return 0;
}
