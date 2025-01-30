#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countUniquePairs(const vector<int>& A) {
    unordered_map<int, int> freq;
    long long total_pairs = 0, same_value_pairs = 0;
    int N = A.size();
    
    for (int num : A) {
        freq[num]++;
    }
    
    total_pairs = (1LL * N * (N - 1)) / 2;
    
 
    for (const auto& i : freq) {
        int key = i.first;
        int count = i.second;
        if (count > 1) {
            same_value_pairs += (1LL * count * (count - 1)) / 2;
        }
    }
    
    return total_pairs - same_value_pairs;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << countUniquePairs(A) << endl;
    return 0;
}