#include <iostream>
#include <vector>

using namespace std;

void findKFactors(int n, int k) {
    vector<int> factors;
    
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

   
    if (n > 1)
        factors.push_back(n);

    
    if ((int)factors.size() < k) {
        cout << "-1\n";
        return;
    }

    
    while ((int)factors.size() > k) {
        factors[factors.size() - 2] *= factors.back();
        factors.pop_back();
    }

    
    for (int num : factors)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    findKFactors(n, k);
    
    return 0;
}
