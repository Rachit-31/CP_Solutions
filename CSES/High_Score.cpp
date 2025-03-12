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
#define in cin >>
#define out cout <<

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
    int n, m;
    in n, in m;
    
    unordered_map<int, list<pii>>adj;
    vector<vector<int>> rev_adj(n + 1); 

    f(i,0,m){
        int a, b, x;
        in a, in b, in x;
        adj[a].pb({b, x});
        rev_adj[b].pb(a);
    }

    vi dist(n+1, -INF);

    dist[1]=0;


    f(i,1,n){
        cf(u,1,n){
            if(dist[u] == -INF) continue;

            for(auto k: adj[u]){
                int v = k.first;
                int w = k.second;
                if(dist[u]+w > dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }
    }


    queue<int>q;
    q.push(n);


    vb vis(n+1, false);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto i: rev_adj[top]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }


    f(i,1,n){
        cf(u,1,n){
            if(dist[u]==-INF) continue;

            for(auto k: adj[u]){
                int v = k.first;
                int w = k.second;

                if(dist[u] + w> dist[v] && vis[v]){
                    out -1 nl;
                    return;
                }
            }
        }
    }
    
    out dist[n] nl;


}

int32_t main() {
    fast_io();
    // int t;  
    // cin >> t;  
    // while (t--) {
    //     solve(); 
    // }

    solve();

    return 0; 
}