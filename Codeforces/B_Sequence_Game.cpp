#include <bits/stdc++.h> 
using namespace std;     

#define int long long        
#define endl '\n'            

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define vi vector<int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define si set<int>
#define sc set<char>

// functions
#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define in cin >>
#define out cout <<

const int MOD = 1e9 + 7;      
const int INF = 1e18;  

int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve() {
    int n;
    in n;
    vi b(n);
    f(i,0,n){
        in b[i];
    }

    vi ans;
    ans.pb(b[0]);

    f(i,1,n){
        if(b[i] != 1 && b[i] < b[i-1]){
            ans.pb(b[i]-1);
            ans.pb(b[i]);
        }
        else if(b[i] == 1 && b[i] < b[i-1]){
            ans.pb(1);
            ans.pb(b[i]);
        }
        else{
            ans.pb(b[i]);
            continue;
        }
    }
    out ans.size()<<endl;
    f(i,0,ans.size()){
        out ans[i]<<" ";
    }
    out endl;
}

int32_t main() {
    fast_io();
    int t;  
    cin >> t;  
    while (t--) {
        solve(); 
    }

    return 0; 
}