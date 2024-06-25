#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Initialize sums for the x, y, and z coordinates
    int sum_x = 0, sum_y = 0, sum_z = 0;

    // Read the vectors and accumulate the sums
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    // Check if the sums of the x, y, and z coordinates are all zero
    if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
