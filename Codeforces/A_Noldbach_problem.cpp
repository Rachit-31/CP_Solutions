#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}


bool noldbach(int n, int k) {
    vector<bool> is_prime = sieve(n);
    vector<int> primes;

    // Collect prime numbers up to n
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    int count = 0;

    // Check neighboring primes and their sum + 1
    for (size_t i = 0; i < primes.size() - 1; i++) {
        int sum = primes[i] + primes[i + 1] + 1;
        if (sum <= n && is_prime[sum]) {
            count++;
        }
    }

    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << (noldbach(n, k) ? "YES" : "NO") << '\n';
    return 0;
}
