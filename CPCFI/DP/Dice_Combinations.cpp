#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
#define MOD 1000000007

ll comb(vector<ll>& f, ll n){

    if(n < 0){
        return 0; 
    }

    if(f[n] != -1){
        return f[n];
    }

    f[n] = 0; 
    for(int i = 1; i <= 6; i++){
        f[n] += comb(f, n-i); 
        f[n] %= MOD; 
    }
    return f[n]; 
}


void solve(){
    
    ll n; 
    cin >> n; 

    vector<ll> formas(n+1, -1); 

    formas[0] = 1; 
    formas[1] = 1; 
    comb(formas, n); 

    cout << formas[n] << endl; 
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