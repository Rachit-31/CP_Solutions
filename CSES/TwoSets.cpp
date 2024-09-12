#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Sum of first n natural numbers
    long long sum = (1LL * n * (n + 1)) / 2;
    
    // If the sum is odd, we cannot divide it into two equal parts
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    
    vector<int> set1, set2;
    long long target = sum / 2;  // We need to form two sets that sum to target
    
    // We start from the largest number n and try to form the first set
    for (int i = n; i >= 1; i--) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;  // Reduce the target
        } else {
            set2.push_back(i);
        }
    }
    
    // Output the two sets
    cout << set1.size() << endl;
    for (int x : set1) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << set2.size() << endl;
    for (int x : set2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
