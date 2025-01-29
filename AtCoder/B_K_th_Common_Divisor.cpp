#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int kthLargestDivisor(int A, int B, int K) {
    int commonGCD = gcd(A, B);
    

    vector<int> divisors;
    for (int i = 1; i * i <= commonGCD; ++i) {
        if (commonGCD % i == 0) {
            divisors.push_back(i);
            if (i != commonGCD / i) {
                divisors.push_back(commonGCD / i);
            }
        }
    }
    

    sort(divisors.rbegin(), divisors.rend());
    

    return divisors[K - 1];
}

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    

    cout << kthLargestDivisor(A, B, K) << endl;
    
    return 0;
}
