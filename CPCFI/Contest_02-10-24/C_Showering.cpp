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
    ll n, s, m; 
    cin >> n >> s >> m;

    if(s > m){
        cout << "NO\n"; 
        return; 
    }

    vector<pair<ll, ll>> nums(n); 

    for(int i = 0; i < n; i++){
        cin >> nums[i].fi; 
        cin >> nums[i].se;
    }

    sort(all(nums)); 

    if(nums[0].fi >= s){
        cout << "YES\n"; 
        return; 
    }

    if(m - nums[n-1].se >= s){
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n; i++){
        int j = i+1; 
        if(j < n && (nums[j].fi - nums[i].se) >= s){
            cout << "YES\n";
            return; 
        }
    }

    cout << "NO\n"; 
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