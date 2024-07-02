#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a){
    for(int i=2; i<a; i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    // m is greaater
    cin>>n>>m;
    int ans=-1;
    for(int i=n+1; i<=m; i++){
        if(isPrime(i)){
            ans=i;
            break;
        }
    }
    if(ans==m){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}