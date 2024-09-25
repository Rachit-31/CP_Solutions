#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        
        int current_max = *max_element(a.begin(), a.end());
        
      
        int global_shift = 0;
        
        while (m--) {
            char op;
            int l, r;
            cin >> op >> l >> r;
            
            if (op == '+') {
                global_shift += 1;
            } else if (op == '-') {
                global_shift -= 1;
            }
            

            cout << current_max + global_shift << " ";
            
        }
        cout<<"---------------"<<endl;
        
        cout << endl;
    }
    
    return 0;
}
