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
    int r, c;
    cin >> r >> c;
    vector<vector<char>> vec(r, vector<char>(c));
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>>(c));
    vector<vector<char>> direction(r, vector<char>(c)); // store direction taken to reach each cell

    // Find start position (A) and take the input
    int sr, sc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    bool found = false;
    int er = -1, ec = -1; // end coordinates of 'B'

    // BFS
    while (!q.empty()) {
        auto top = q.front();
        int x = top.first;
        int y = top.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = x + row[i];
            int newy = y + col[i];

            if (newx >= 0 && newx < r && newy >= 0 && newy < c && !vis[newx][newy] && vec[newx][newy] != '#') {
                vis[newx][newy] = true;
                parent[newx][newy] = {x, y}; // store parent cell
                direction[newx][newy] = dir[i]; // store direction taken
                q.push({newx, newy});

                if (vec[newx][newy] == 'B') {
                    found = true;
                    er = newx;
                    ec = newy;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        // Backtrack to get the path
        string ans;
        while (!(er == sr && ec == sc)) {
            ans += direction[er][ec];
            auto top1 = parent[er][ec];
            int px = top1.first;
            int py = top1.second;
            er = px;
            ec = py;
        }
        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;
        cout << ans << endl;
    }
}

int32_t main() {

        solve(); 

    return 0; 
}