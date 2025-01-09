#include <bits/stdc++.h> 
using namespace std;     

#define int long long        


#define endl '\n'            

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 

const int MOD = 1e9 + 7;      
const int INF = 1e18;       


int mod_add(int a, int b, int m = MOD) { 
    return ((a % m) + (b % m)) % m; 
}


int mod_sub(int a, int b, int m = MOD) { 
    return ((a % m) - (b % m) + m) % m; 
}


int mod_mul(int a, int b, int m = MOD) { 
    return ((a % m) * (b % m)) % m; 
}


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl; 
#else
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);


template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}


template <class T> void _print(vector <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}


template <class T> void _print(set <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}


template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; 
    for (auto i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}


template <class T> void _print(multiset <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); cerr << " ";
    } 
    cerr << "]";
}


void solve() {
    int m, a, b, c;
    cin>>m;
    cin>>a;
    cin>>b;
    cin>>c;

    int ans =0;
    int ts = 2*m;
    int fr = m;
    int sr = m;

    if(a >= fr){
        ans += fr;
        ts -= fr;
    }
    else{
        fr -= a;
        ts -= a;
        ans += a;
    }


    if(b >= sr){
        ans += sr;
        ts -= sr;
    }
    else{
        sr -= b;
        ts -= b;
        ans += b;
    }


    if(ts > 0){
        if(c>=ts){
            ans += ts;
        }
        else{
            ans += c;
        }
    }


    cout<<ans<<endl;
}

int32_t main() {
    
    int t;  
    cin >> t;  
    while (t--) {
        solve(); 
    }

    return 0; 
}
