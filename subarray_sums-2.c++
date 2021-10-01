#include <bits/stdc++.h>
using namespace std ;
using namespace std::chrono;
 
#define ll long long 
#define pb push_back 
#define yes cout << "YES" 
#define no cout << "NO" 
#define all(x) (x).begin(),(x).end()
 
const long long int mod = 1e9 + 7 ;
const long long int INF = 1e18 ;
 
void readvec(vector<ll> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cin >> v[i] ;
    }
}
 
void printvec(vector<ll> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
}
 
//For debugging :
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
//binary exponentiation 
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
 
void solve(){
    ll n, x; cin >> n >> x; 
    vector<ll> v(n);
 
    if(x == 0){
        cout << n*(n+1)/2 ;
        return ;
    }
    map<ll,ll> m ;
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
 
    //prefix array :
    vector<ll> prefix(n); prefix[0] = v[0];
    for(int i = 1 ; i < n ; i++) prefix[i] = prefix[i-1] + v[i] ;
 
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        m[prefix[i]]++;
        ll remaining = prefix[i] - x;
        if(remaining == 0){
            ans++;
        }
        ans += m[(remaining)];
    }
    cout << ans ;
}
 
int main(){
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
 
    int tests = 1 , test_case = 1;
    // cin >> tests ;
    while(tests--){
        cout << setprecision(15) << fixed ;
        solve() ;
        cout << '\n' ;
        // cout << "Case #" << test_case << ": " << ans << '\n' ;
    }
 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "\n\nTime taken : " << fixed << duration.count() / 1000000.0 << "seconds" << "\n";
}