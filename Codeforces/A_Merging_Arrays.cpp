#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<int> merged;
    merged.reserve(n + m);
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }
    
    while (i < n) merged.push_back(a[i++]);
    while (j < m) merged.push_back(b[j++]);
    
    for (int num : merged) cout << num << " ";
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    mergeSortedArrays(a, b);
    return 0;
}
