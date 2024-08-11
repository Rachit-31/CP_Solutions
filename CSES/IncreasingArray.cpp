#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    long long moves =0;
    for(int i=0; i<n-1; i++){
        int f = nums[i];
        int s = nums[i+1];

        if(f > s){
            moves += f-s;
            nums[i + 1] = f;
        }
    }

    cout<<moves<<endl;
    return 0;
}