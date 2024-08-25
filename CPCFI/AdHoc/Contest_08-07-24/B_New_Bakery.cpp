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
    ll n, a, b; 
    cin >> n >> a >> b; 

    ll k = b - a; 

    k = min(k, n); 

    ll total = 0; 

    if(k >= 1){
        ll suma = b*(b+1) / 2;     
        suma = suma - (b-k)*(b-k+1)/2; 

        total = suma + (n-k)*a; 
    }
    else{
        total = n*a; 
    }

    cout << total << "\n"; 
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