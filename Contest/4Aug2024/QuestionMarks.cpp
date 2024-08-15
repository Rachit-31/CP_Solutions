#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a= 4*n;
        string s;
        bool allQuesmark =1;
        int n1= s.length();

        for(int i=0; i<n1; i++){
            if(s[i] != '?'){
                allQuesmark =0;
            }
        }

        if(allQuesmark){
            return 0;
        }

        unordered_map<char, int>m;
        for(int i=0; i<n1; i++){
            m[s[i]]++;
        }

        int quesCnt = m['?'];

        int ans=0;
        for(auto pair: m){
            char ch= pair.first;
            int charcnt= pair.second;

            if(ch != '?' && charcnt >= n){
                ans += n;
            }
            else if(ch != '?' && charcnt<n && quesCnt >= n - charcnt){
                ans += n - charcnt;
                quesCnt -=  n-charcnt;
            }
        }

        cout<< ans<<endl;
        cout<<endl;
        cout<<endl;

    }
    return 0;
}