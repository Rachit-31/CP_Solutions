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

int findPeak(vi &p){
    int s =0, e=p.size()-1;
    while(s < e){
        int mid= s + (e-s)/2;
        if(p[mid] > p[mid+1]){
            e = mid;
        }
        else{
            s = mid+1;
        }
    }

    return s;

}
void solve() {
    int n;
    in n;
    vi p(n);
    f(i,0,n){
        in p[i];
    }

    f(j,1,n-1){
        if(p[j - 1] < p[j] && p[j] > p[j + 1]){
            yes();
            out j << " " << j + 1 << " " << j + 2 << "\n";
            return;
        }
    }
    no();
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