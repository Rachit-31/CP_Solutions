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

int findParent(int node, vi &parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node]= findParent(parent[node], parent);
}
void makeunion(int u, int v, vi &rank, vi &parent){
    u= findParent(u, parent);
    v= findParent(v, parent);

    if(u!=v){
        if(rank[u] > rank[v]){
            parent[v]=u;
        }
        else if(rank[v] > rank[u]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }

}
// int cntchild(int node, vi &parent){
//     int par= findParent(node, parent);

//     int cnt=0;
//     cf(i,1,parent.size()){
//         if(parent[i]==par){
//             cnt++;
//         }
//     }

//     return cnt;
// }
void solve() {
    int n, m;
    in n>>m;

    vi parent(n+1);
    cf(i,1,n){
        parent[i]=i;
    }

    vi rank(n+1,0);
    f(i,0,m){
        int k;
        in k;
        vi mem(k);
        ivi(mem);

        if(k>0){
            int par= mem[0];
            f(i,1,k){
                makeunion(par, mem[i], rank, parent);
            }
        }
    }

    vi ans;
    vector<int> compSize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int p = findParent(i, parent);
        compSize[p]++; 
    }


    for (int i = 1; i <= n; i++) {
        cout << compSize[findParent(i, parent)] << " ";
    }
}

int32_t main() {
    fast_io();

    solve();

    return 0; 
}