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

#define INF INT_MAX

ll min_monedas(vll& dp, vll& coins, ll x){

    if(x == 0)
        return 0; 

    if(x < 0)
        return INF;

    if(dp[x] != -1)
        return dp[x]; 

    ll min_mon = INF; 
    for(auto m: coins){
        min_mon = min(1 + min_monedas(dp, coins, x-m), min_mon); 
    }

    dp[x] = min_mon;  

    return dp[x]; 
}


void solve(){
    ll n, x; 
    cin >> n >> x; 

    vll coins(n); 
    read_vll(coins, n); 

    vll dp(x+1, -1); 

    ll res = min_monedas(dp, coins, x); 

    if(res == INF){
        cout << -1;
    }
    else{
        cout << res; 
    }
    cout << "\n"; 
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