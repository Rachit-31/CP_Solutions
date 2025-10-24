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
const int MAX_COLOUR = 100000;

int func(vi &v){
    sort(rall(v));

    int sum=0;
    int n= v.size();
    for(int i = 0, j = n-1; i < n; i++, j -= 2) {
        sum += 1LL * j * v[i];
    }

    return sum;
}
void solve() {
    int n,m;

    in n>>m;

    vector<vi>a(n, vi(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            in a[i][j];
            a[i][j]--;
        }
    }

    vector<vi>x(MAX_COLOUR);
    vector<vi>y(MAX_COLOUR);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            x[a[i][j]].pb(i);
            y[a[i][j]].pb(j);
        }
    }

    int ans=0;
    for(int colour = 0; colour < MAX_COLOUR; colour++) { 
        ans += func(x[colour]);
        ans += func(y[colour]);
    }
    out ans nl;
}

int32_t main() {
    fast_io();

    solve();

    return 0; 
}