#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculateTypingTime(const string& s) {
    if (s.empty()) return 0;
    int time = 2; // Time to type the first character
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

int main() {
    int t;
    cin>>t;
    while(t--){
            string s;
    cin >> s;
    int maxTime = 0;
    char bestChar = 'a';
    int bestPosition = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i <= s.size(); ++i) {
            string newPassword = s.substr(0, i) + c + s.substr(i);
            int newTime = calculateTypingTime(newPassword);
            if (newTime > maxTime) {
                maxTime = newTime;
                bestChar = c;
                bestPosition = i;
            }
        }
    }

    
    string result = s.substr(0, bestPosition) + bestChar + s.substr(bestPosition);
    cout << result << endl;
    }
    
    return 0;
}
