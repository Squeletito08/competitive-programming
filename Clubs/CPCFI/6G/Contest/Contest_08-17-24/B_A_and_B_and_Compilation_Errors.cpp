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

    int n; 
    cin >> n; 

    vi err(n);

    multiset<int> err_mult; 
    multiset<int> err_mult2; 

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        err[i] = x; 
        err_mult.insert(x); 
    }

    err_mult2 = err_mult; 

    int error_1 = 0; 

    for(int i = 0; i < n-1; i++){
        int x; 
        cin >> x; 

        auto it = err_mult.find(x); 
        err_mult.erase(it); 
    }

    error_1 = *err_mult.begin(); 

    auto it = err_mult2.find(error_1); 
    err_mult2.erase(it); 

    for(int i = 0; i < n-2; i++){
        int x; 
        cin >> x; 

        auto it = err_mult2.find(x);
        err_mult2.erase(it);
    }

    int error2 = *err_mult2.begin(); 

    cout << error_1 << "\n"; 
    cout << error2 << "\n"; 
    
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