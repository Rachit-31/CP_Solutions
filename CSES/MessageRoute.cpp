#include <bits/stdc++.h> 
using namespace std;     

#define int long long        

// Replaces 'endl' with '\n' for faster output (as 'endl' flushes output buffer)
#define endl '\n'            

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

const int MOD = 1e9 + 7;      // For modular arithmetic
const int INF = 1e18;         // A very large value used for initialization

// Function to perform modular addition
int mod_add(int a, int b, int m = MOD) { 
    return ((a % m) + (b % m)) % m; 
}

// Function to perform modular subtraction
int mod_sub(int a, int b, int m = MOD) { 
    return ((a % m) - (b % m) + m) % m; 
}

// Function to perform modular multiplication
int mod_mul(int a, int b, int m = MOD) { 
    return ((a % m) * (b % m)) % m; 
}

// Debugging tools - active only when not in a competitive environment
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;  // Macro to print debug information
#else
#endif

// Print functions for debugging various data types
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

// Templates for printing containers (like vector, set, etc.) in debugging
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

// Template to print a pair
template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}

// Template to print a vector
template <class T> void _print(vector <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}

// Template to print a set
template <class T> void _print(set <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}

// Template to print a map
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; 
    for (auto i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}

// Template to print a multiset
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}


void solve() {
    int n, m;
    cin>>n;
    cin>>m;

    int src = 1;
    int dest = n;

    unordered_map<int, list<int>>adj;
    // undirected graph
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a;
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>parent(n+1, -1);
    vector<bool>vis(n+1, false);

    queue<int>q;
    q.push(src);
    vis[src] = true;
    int pathLength = 1;
    bool found = false;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int top = q.front();
            q.pop();

            if(top == dest){
                found = true;
                break;
            }
            for(auto nbr: adj[top]){
                if(!vis[nbr]){
                    parent[nbr] = top;
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        if(found){
            break;
        }
        pathLength++;
    }

    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int>ans;
    int currentNode = dest;
    ans.push_back(currentNode);

    while(currentNode != src){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());

    cout<<pathLength<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}

int32_t main() {
    
        solve(); 

    return 0; 
}