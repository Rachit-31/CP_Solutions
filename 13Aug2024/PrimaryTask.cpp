// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int a;
//         cin>>a;

//         string s = to_string(a);
//         int n= s.length();

//         if(n <= 2){
//             cout<<"No"<<endl;
//             continue;
//         }
//         if(s[0] != '1' || s[1] != '0'){
//             cout<<"No"<<endl;
//             continue;
//         }

//         string temp = s.substr(0, 2);
//         string rem = s.substr(2);

//         if(stoi(rem) < 2){
//             cout<<"No"<<endl;
//             continue;
//         }
//         if(rem[0] == '0'){
//             cout<<"No"<<endl;
//         }
//         else {
//             cout<<"Yes"<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;

        string s = to_string(a);
        int n = s.length();

        if(n <= 2){
            cout << "No" << endl;
            continue;
        }
        
        if(s.substr(0, 2) != "10"){
            cout << "No" << endl;
            continue;
        }

        string rem = s.substr(2);

        // Check if rem is a valid exponent (i.e., a number >= 2)
        int exponent = stoi(rem);
        if(exponent >= 2 && rem[0] != '0'){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
