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

int func(int curridx, int previdx, int currrow, int prevrow, vi &a, vi &b, vector<vector<int>>&dp){
    if(curridx == a.size()){
        return 0;
    }

    if(dp[curridx][currrow]!=-1){
        return dp[curridx][currrow];
    }

    int take =0;
    if(previdx == -1 || (curridx>previdx && prevrow != currrow)){
        take = (currrow==0 ? a[curridx] : b[curridx]) + func(curridx+1, curridx, 1-currrow, currrow,a,b,dp);
    }

    int nottake = func(curridx+1, previdx, currrow, prevrow,a,b, dp);
    

    return dp[curridx][currrow]=max(take, nottake);
}
void solve() {
    int n;
    in n;

    vi a(n), b(n);
    ivi(a);
    ivi(b);
    vector<vector<int>>dp(n, vector<int>(2,-1));
    int ans = max(func(0, -1, 0, -1, a, b,dp),func(0, -1, 1, -1, a, b, dp));

    out ans nl;
}

int32_t main() {
    fast_io();

    solve();

    return 0; 
}