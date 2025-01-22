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
    ll n; 
    cin >> n; 

    vll nums(n); 

    for(ll i = 0; i < n; i++){
        ll x; 
        cin >> x; 
        nums[i] = x - i; 
    }

    map<ll, ll> aux; 

    for(ll i = 0; i < n; i++){
        aux[nums[i]]++; 
    }

    ll res = 0; 

    for(ll i = 0; i < n; i++){
        if(aux.count(nums[i])){
            aux[nums[i]]--; 
            res += aux[nums[i]]; 
        }
    }

    cout << res << "\n"; 
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