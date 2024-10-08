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

#define MAXIMO 200002

void solve(){
    
    int n, k, q; cin >> n >> k >> q; 

    vi recipes(MAXIMO, 0); 
    vi reciPref(MAXIMO, 0); 

    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r; 
        recipes[l] += 1; 
        recipes[r+1] += -1; 
    }

    for(int i = 1; i < MAXIMO; i++){
        reciPref[i] = recipes[i] + reciPref[i-1]; 
    }

    vi validos(MAXIMO, 0); 

    for(int i = 0; i < MAXIMO; i++){
        if(reciPref[i] >= k){
            validos[i] = 1; 
        }
    }

    vi validosPref(MAXIMO, 0); 

    for(int i = 1; i < MAXIMO; i++){
        validosPref[i] = validos[i] + validosPref[i-1];
    }

    while(q--){
        int a, b; cin >> a >> b; 
        cout << validosPref[b] - validosPref[a-1] << "\n"; 
    }
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