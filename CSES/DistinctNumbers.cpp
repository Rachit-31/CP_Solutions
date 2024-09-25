#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    set<int>nums;
    for(int i=0; i<n; i++){
        int j;
        cin>>j;
        nums.insert(j);
    }

    cout<<nums.size();
}
int main(){
    solve();
    return 0;
}