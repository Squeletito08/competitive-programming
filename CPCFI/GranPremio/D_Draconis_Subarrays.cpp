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
    ll m, n; 
    cin >> m >> n; 

    vll M(m);
    vll N(n); 

    read_vll(M, m); 
    read_vll(N, n); 

    vll pos; 

    ll inicio = M[0]; 
    for(int i = 0; i < n - m + 1; i++){
        pos.pb(inicio - N[i]); 
    }

    vll pref(n+1, 0); 

    for(int i = 1; i < n+1; i++){
        pref[i] = pref[i-1] + N[i-1]; 
    }

    int ctd = 0; 

    ll total = 0; 

    for(int i = 0; i < m; i++){
        total += M[i]; 
    }

    for(int i = 0; i < n-m+1; i++){
        ll suma = pref[i+m] - pref[i]; 

        if(suma + pos[i]*m == total)
            ctd++; 
    }

    cout << ctd << "\n"; 
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