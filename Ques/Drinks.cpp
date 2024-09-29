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
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    double orange = 0.0;
    for(auto i: nums){
        orange += static_cast<double>(i)/100;
    }
    double total = n;
    double ans = (orange / total) * 100;
    cout<<ans;
}

int32_t main() {

    solve();

    return 0; 
}
