#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl << '\n'

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(a) (int)a.size()
#define pii pair<int, int>

#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mi map<int, int>
#define umi unordered_map<int, int>
#define umc unordered_map<char, int>
#define ums unordered_map<string, int>
#define si set<int>
#define sc set<char>

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

void ivi(vi &v){
    int n = v.size();
    f(i,0,n){
        in v[i];
    }
}

void solve() {
    int n;
    in n;

    vi s(n);
    ivi(s);

    unordered_map<int, vector<int>> mpp;
    for (int i = 0; i < n; ++i) {
        mpp[s[i]].push_back(i);
    }
    for (auto &kv : mpp) {
        if (kv.second.size() == 1) {
            out -1 nl;
            return;
        }
    }
    vi perm(n, -1);
    for (auto &kv : mpp) {
        auto &idx = kv.second;
        int m = (int)idx.size();
        for (int i = 0; i < m; ++i) {
            int from = idx[i];
            int to = idx[(i + 1) % m];
            perm[from] = to;
        }
    }
    for (int i = 0; i < n; ++i) {
        out perm[i] + 1 << " ";
    }
    cout<<endl;
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
