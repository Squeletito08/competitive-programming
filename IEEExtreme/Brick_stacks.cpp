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
    ll n, x; cin >> n >> x; 

    multiset<ll> ms;

    for(int i = 0; i < n; i++){
        ll x; cin >> x; 
        ms.insert(x); 
    }

    vector<vll> fin; 

    while(!ms.empty()){
        auto it = ms.begin(); 
        vector<ll> res; 
        while(it != ms.end()){
            res.pb(*it); 
            ms.erase(it); 
            it = upper_bound(all(ms), *it+x-1); 
        }

        if(sz(res) != 1 || sz(res) != 0)
            fin.pb(res); 
    }

    cout << sz(fin) << endl; 

    for(auto x: fin){
        cout << sz(x) << " ";
        for(int i = sz(x)-1; i >= 0; i--){
            cout << x[i] << " "; 
        }
        cout << endl; 
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int t = 1; 

    while(t--){
        solve(); 
    }

    return 0; 
}