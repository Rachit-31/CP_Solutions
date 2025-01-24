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

    int solve(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        if (i == word1.length()) return word2.length() - j; 
        if (j == word2.length()) return word1.length() - i;

        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return solve(i+1, j+1, word1, word2, dp);
        }
        // insert
        int opt1 = 1 + solve(i,j+1, word1, word2, dp);

        // delete
        int opt2 = 1 + solve(i+1, j, word1, word2, dp);

        // replace
        int opt3 = 1 + solve(i+1, j+1, word1, word2, dp);


        return dp[i][j] = min({opt1, opt2, opt3});
    }
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; 
    for (int j = 0; j <= n; j++) dp[0][j] = j;

   
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    
                                    dp[i][j - 1],    
                                    dp[i - 1][j - 1] 
                                   });
            }
        }
    }

    return dp[m][n];
}

int32_t main() {
    fast_io();
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>>dp(n1, vector<int>(n2, -1));
    // cout<<solve(0,0,s1, s2, dp); 
    cout<<minDistance(s1,s2);
    

    return 0; 
}