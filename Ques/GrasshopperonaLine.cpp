#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t; 
    while (t--) {
        int x, k;
        cin >> x >> k;

        vector<int> ans;
        int temp = x;

        
        while (temp != 0) {
            
            int jump = (temp > 0 ? temp : -temp);
            while (jump % k == 0) {
                jump--;
            }

           
            if (temp > 0) {
                ans.push_back(jump);
                temp -= jump;
            } else {
                ans.push_back(-jump);
                temp += jump;
            }
        }

        
        cout << ans.size() << endl;
        for (auto jump : ans) {
            cout << jump << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
