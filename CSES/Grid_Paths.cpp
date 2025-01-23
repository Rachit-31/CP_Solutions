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

vector<vector<int>> dp;
int solve(int i, int j, vector<vector<char>> &grid) {
    int n = grid.size();

    if (i >= n || j >= n || grid[i][j] == '*') {
        return 0;
    }

    if (i == n - 1 && j == n - 1) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    
    int opt1 = solve(i + 1, j, grid);   
    int opt2 = solve(i, j + 1, grid);   

    
    return dp[i][j] = (opt1 + opt2) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    f(i, 0, n) {
        f(j, 0, n) {
            cin >> grid[i][j];
        }
    }

    
    dp.assign(n, vector<int>(n, -1));

    
    cout << solve(0, 0, grid) << endl;

    return 0;
}