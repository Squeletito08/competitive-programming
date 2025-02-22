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


ll comb(vector<ll>& dp, vector<ll>& coins, ll x){

    if(x < 0){
        return 0; 
    }

    if(x == 0){
        return 1; 
    }

    if(dp[x] != -1){
        return dp[x]; 
    }

    dp[x] = 0; 

    for(ll i = 0; i < coins.size(); i++){
        dp[x] += comb(dp, coins, x-coins[i]); 
        dp[x] %= MOD; 
    }

    return dp[x]; 
}


void solve(){
    ll n, x; 
    cin >> n >> x; 

    vector<ll> coins(n); 
    vector<ll> dp(x+1, -1); 

    for(int i = 0; i < n; i++){
        cin >> coins[i]; 
    }

    comb(dp, coins, x); 

    cout << dp[x] << endl; 
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