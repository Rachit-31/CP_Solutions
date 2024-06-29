#include<iostream>
using namespace std;
void decodePassword(string s, string &ans){
    int n= s.length();
    int i=0;
    while( i<n ){
        if(s[i]=='.'){
            ans.push_back('0');
            i++;
        }
        else{
            if(s[i]=='-'){
                if(s[i+1]=='-'){
                    ans.push_back('2');
                }
                else if(s[i+1]=='.'){
                    ans.push_back('1');
                }
                i=i+2;
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    string ans="";
    decodePassword(s, ans);
    cout<<ans<<endl;
    return 0;
}