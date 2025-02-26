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
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
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
void printi(vi &v){
    f(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void printc(vc &v){
    f(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void prints(vs &v){
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

int nextGreater(int i, vi &nums){
    int n = nums.size();
    int s=0, e=n-1;
    int ans =0;
    while(s<=e){
        int mid = s+(e-s)/2;

        if(nums[mid] >= i){
            ans = nums[mid];
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return ans;
}
void solve() {
    int n;
    in n;
    char c;
    in c;
    string s;
    in s;
    string s1 = s+s;
    
    vi v;
    int n1 = s1.length();
    f(i,0,n1){
        if(s1[i] == 'g'){
            v.pb(i);                        //O(2n)
        }
    }
    int ans = -1;
    int x = v.size();
    f(i,0,n){
        char ch = s[i];
        if(ch == c){
            int idx = nextGreater(i, v);
            // out "at every iteration idx is"<<idx nl;

                                            //O(n*log(x))
            ans = max(ans, idx-i);
        }
    }

    // o(2*n)+O(n*log(v.size()))
    //O(nlogn)
    out ans nl;

}

int32_t main() {
    fast_io();
    int t;  
    cin >> t;  
    while (t--) {
        solve(); 
    }
    // solve();

    return 0; 
}