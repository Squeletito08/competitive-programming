#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
const ll MOD = 1e9+7;


void solve(){
    ll a, b; cin >> a >> b; 

    ll res = 1; 

    int i = 0; 
    while(b){
        cout << " i -> " << i << endl; 
        cout << " res -> " << res << endl; 
        cout << " a -> " << a << endl; 
        if(b % 2 != 0){
            res *= a; 
            res %= MOD; 
        }
        a *= a; 
        a %= MOD; 
        b >>= 1; 
        i++; 
    }

    cout << res << endl; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int t = 1; 
    cin >> t; 

    while(t--){
        solve(); 
    }

    return 0; 
}