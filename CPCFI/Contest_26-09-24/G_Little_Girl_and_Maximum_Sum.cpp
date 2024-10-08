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


void solve(){
    ll n, q; cin >> n >> q; 
  
    vll nums(n); 
    read_vll(nums, n); 

    vll querys(n+2, 0); 

    while(q--){
      ll l, r; cin >> l >> r; 
      querys[l] += 1; 
      querys[r+1] += -1; 
    }

    vll prefixQuerys(n+1, 0); 

    for(ll i = 1; i < n+1; i++){
      prefixQuerys[i] = querys[i] + prefixQuerys[i-1];
    }

    sort(all(prefixQuerys)); 
    sort(all(nums)); 

    ll sum = 0; 

    for(ll i = 1; i < prefixQuerys.size(); i++){
      sum += prefixQuerys[i] * nums[i-1]; 
    }

    cout << sum << "\n"; 
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