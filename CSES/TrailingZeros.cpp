#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;

    // Count factors of 5
    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << trailingZeroes(n) << endl;
    return 0;
}
