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

void cribaAlg (vector<bool>& criba, int j){
    criba[0] = criba[1] = false; 

    for(int i = 2; i*i <= j; i++){
        if(criba[i]){
            for(int k = 2; k*i <= j; k++){
                criba[i*k] = false; 
            }
        }
    }
}


void solve(){
    int i, j; 
    cin >> i >> j; 

    vector<bool> criba(j+1, true); 

    cribaAlg(criba, j); 

    int cont = 0; 

    for(int k = i; k <= j; k++){
        if(criba[k])
            cont++; 
    }

    cout << cont << "\n"; 
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