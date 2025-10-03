#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define nl <<'\n'           

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define sz(a) (int)a.size()
#define pii pair<int, int>

#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define mi map<int, int>
#define umi unordered_map<int, int>
#define umc unordered_map<char, int>
#define ums unordered_map<string, int>
#define si set<int>
#define sc set<char>

// functions
#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e;i>=s;i--)
#define pb push_back
#define bk back
#define F first
#define S second
#define in cin >>
#define out cout <<
#define spc <<" "

const int MOD = 1e9 + 7;      
const int INF = 1e18;  

int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
bool prime(int n){
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++){
        if (n % x == 0)
            return false;
    }
    return true;
}
void ovi(vi &v){
    f(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void ovc(vc &v){
    f(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void ovs(vs &v){
    f(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void ivi(vi &v){
    int n = v.size();
    f(i,0,n){
        in v[i];
    }
}
void ivc(vc &v){
    int n = v.size();
    f(i,0,n){
        in v[i];
    }
}
void ivs(vs &v){
    int n = v.size();
    f(i,0,n){
        in v[i];
    }
}

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve() {
    int n;
    in n;
    string s;
    in s;

    char s1='-1', s2='-1';
    int l=0, r=n-1;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            s1=s[l];
            s2=s[r];
            break;
        }
    }

    if(s1=='-1' && s2=='-1'){
        out 0 nl;
        return;
    }

    // case1 s1
    l=0, r=n-1;
    int cnt1=0;
    while(l<=r){
        if(s[r] == s[l]){
                r--;
                l++;
        }
        else if(s[l] == s1){
            l++;
            cnt1++;
        }
        else if(s[r] == s1){
            r--;
            cnt1++;
        }
        else{
            cnt1= 1e9;
            break;
        }
    }


    l=0, r=n-1;
    int cnt2=0;
    while(l<=r){
        if(s[r] == s[l]){
                r--;
                l++;
        }
        else if(s[l] == s2){
            l++;
            cnt2++;
        }
        else if(s[r] == s2){
            r--;
            cnt2++;
        }
        else{
            cnt2= 1e9;
            break;
        }
    }

    out ((min(cnt1, cnt2) == 1e9) ? -1 : min(cnt1, cnt2)) nl;
}

int32_t main() {
    fast_io();
    int t;  
    cin >> t;  
    while (t--) {
        solve(); 
    }

    // solve();

    return 0; 
}