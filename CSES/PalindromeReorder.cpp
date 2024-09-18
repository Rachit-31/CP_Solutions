#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;

    unordered_map<char, int> freq;  // Frequency map for each character

    for (char c : str) {
        freq[c]++;
    }

    int odd_count = 0; 
    char odd_char = 0; 

    
    for (auto entry : freq) {
        if (entry.second % 2 != 0) {
            odd_count++;
            odd_char = entry.first;
        }
    }

    
    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    string half = "";  

   
    for (auto entry : freq) {
        half += string(entry.second / 2, entry.first);
    }

    // The palindrome will be `half + odd_char + reverse(half)` if odd_char exists
    string result = half;
    if (odd_count == 1) {
        result += odd_char;  // Add the odd character in the middle
    }
    reverse(half.begin(), half.end());  // Mirror the first half
    result += half;

    cout << result << endl;
}

int main() {
    solve();
    return 0;
}
