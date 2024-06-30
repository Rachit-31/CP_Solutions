// Basil's Garden
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        int n;
        cin>>n;
        vector<int>h(n);
        for(int i=0; i<n; i++){
            cin>>h[i];
        }

        while(true){
            cnt++;
            bool all_zero = true;
            for(int i=0; i<n; i++){
                if(i==n-1 || h[i] > h[i+1]){
                    h[i]=max(0, h[i]-1);
                }
                if(h[i]>0){
                    all_zero=false;
                }
            }
            if(all_zero){
                break;
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}