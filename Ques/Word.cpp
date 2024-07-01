#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int uppernums=0, lowernums=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z'){
            lowernums++;
        }
        else{
            uppernums++;
        }
    }

    if(lowernums>=uppernums){
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    else{
        for(int i=0; i<s.length(); i++){
            if(s[i] >='a' && s[i]<='z'){
                s[i]=s[i]-'a'+'A';
            }
        }
    }

    cout<<s<<endl;

    return 0;
}