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
    string s;
    cin >> s;

    vector<int> nums;

    for (auto i : s) {
        if (i != '+') {
            if (i == '1') nums.push_back(1);
            else if (i == '2') nums.push_back(2);
            else if (i == '3') nums.push_back(3);
        }
    }

    sort(nums.begin(), nums.end());

    string ans = "";
    for (int i = 0; i < nums.size(); i++) {
        ans += to_string(nums[i]);
        if (i != nums.size() - 1) {
            ans += '+';
        }
    }

    cout << ans << endl;
}

int32_t main() {
    
   
        solve(); 
   

    return 0; 
}
