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

int dfs(int l, int r, vi &a, int n, int k, int sum, vector<vector<vector<int>>>&dp){
    
    if(k==0) return sum;

    if(dp[l][r][k] != -1){
        return dp[l][r][k];
    }

    if (l + 1 <= r) {
        int op1 = dfs(l + 2, r, a, n, k - 1, sum - (a[l] + a[l + 1]), dp);
        int op2 = dfs(l, r - 1, a, n, k - 1, sum - a[r], dp);
        return dp[l][r][k] =max(op1, op2);
    } else {
        return dp[l][r][k] =dfs(l, r - 1, a, n, k - 1, sum - a[r], dp);
    }
}
void solve() {
    int n, k;
    in n>>k;
    vi a(n);
    ivi(a);

    sort(a.begin(), a.end());
    // int total = accumulate(all(a), 0LL);
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    // out dfs(0, n - 1, a, n, k, total, dp) nl;

    vi pr(n+1, 0);
    f(i,0,n){
        pr[i+1]= pr[i]+a[i];
    }

    int ans=0;
    for(int m=0; m<=k; m++){
        int left= 2*m;
        int right = n-(k-m);

        if(left<=right){
            int sum= pr[right]-pr[left];
            ans= max(ans, sum);
        }
    }

    out ans nl;
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