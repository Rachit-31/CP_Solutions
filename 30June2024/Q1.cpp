// Upload More RAM
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int result = n * k - (k - 1);
        cout << result << endl;
    }
    return 0;
}