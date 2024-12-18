#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        vector<int> nums(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            freq[nums[i]]++;
        }

        if (freq.size() > 2) {
            cout << "No" << endl;
            continue;
        }

        vector<int> counts;
        for (auto& i : freq) {
            int value = i.second;
            counts.push_back(value);
        }

        if (freq.size() == 1) {
            cout << "Yes" << endl;
        } else {
            if (abs(counts[0] - counts[1]) <= 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
