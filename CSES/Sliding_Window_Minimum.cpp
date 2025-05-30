#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;


    deque<int> dq;

    
    vector<long long> window(k);
    long long xor_result = 0;

    
    window[0] = x;

    
    for (int i = 0; i < n; ++i) {
        
        if (i > 0) {
            x = (a * x + b) % c;
            if (i < k) {
                window[i] = x;
            } else {
                window[i % k] = x;  
            }
        }

        
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && window[dq.back() % k] >= window[i % k]) {
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1) {
            xor_result ^= window[dq.front() % k];
        }
    }

    cout << xor_result << '\n';
    return 0;
}
