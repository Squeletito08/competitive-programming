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


void solve(vll& suc){
    ll n; 
    cin >> n; 

    int cont = 0; 

    if(n < 2){
        cout << 0 << "\n"; 
        return;
    }

    while(n >= 2){
        auto it = lower_bound(suc.begin(), suc.end(), n); 

        if(*it > n){
            it--; 
        }
        
        if(it != suc.end()){
            cont++; 
            n -= *it; 
        } 
    }

    cout << cont << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    ll max = 1000000000; 

    vector<ll> suc;

    suc.pb(2);  

    for(int i = 1; i < max; i++){
        ll sig = suc[i-1] + 2*(i+1) + i; 
        suc.pb(sig); 

        if(sig >= max){
            break; 
        }
    }


    int t = 1; 
    cin >> t; 

    while(t--){
        solve(suc); 
    }

    return 0; 
}