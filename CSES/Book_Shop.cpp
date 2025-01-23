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

const int MOD = 1e9 + 7;      
const int INF = 1e18;  

int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int solve(int i, int x, vi &cost, vi &pages, int currCost, vector<vector<int>>&dp) {
    if(currCost > x){
        return 0;
    }

    if(i == cost.size()){
        return 0;
    }

    if(dp[i][currCost] != -1){
        return dp[i][currCost];
    }
    // opt1 
    int opt1 =0;
    
    if(currCost + cost[i] <= x){
        opt1 = pages[i] + solve(i+1, x, cost, pages, currCost + cost[i], dp);
    }


    // opt2
    int opt2 = solve(i+1, x, cost, pages, currCost, dp);

    return dp[i][currCost]=max(opt1, opt2);
}
int solveTab(vi& cost, vi& pages, int n, int x){
    int sum = accumulate(cost.begin(), cost.end(), 0);
    vi dp(x + 1, 0);
    
     f(i, 0, n) {
        
        for (int j = x; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }
    }

    return dp[x];
}
int32_t main() {
    fast_io();
    int n, x;
    cin>>n;
    cin>>x;
    vi cost(n);
    vi pages(n);

    f(i,0,n){
        cin>>cost[i];
    }
    f(i,0,n){
        cin>>pages[i];
    }

    // int sum = accumulate(cost.begin(), cost.end(), 0);
    // vector<vector<int>>dp(n+1, vector<int>(sum, -1));
    int ans = solveTab(cost, pages, n,x);

    cout<<ans<<endl;

    return 0; 
}