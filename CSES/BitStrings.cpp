#include <bits/stdc++.h>
using namespace std;

// ---------------THE TIME COMPLEXITY OF THIS ALGO IS O(logN)

// Function to compute (base^exp) % mod using iterative modular exponentiation
long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        // If exp is odd, multiply the current base with the result
        if (exp % 2 == 1)
            result = (result * base) % mod;
        
        // Square the base and reduce exp by half
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    const int MOD = 1000000007;

    // Compute 2^n % MOD using modular exponentiation
    long long result = modExpo(2, n, MOD);

    cout << result << endl;
    return 0;
}
