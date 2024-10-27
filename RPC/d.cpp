#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
const ll MOD = 1e9+7;

int numRondas(int x1, int x2){


    if(x2 == 0 || (x2 == 1 && x1 == 0)){
        return 0; 
    }

    if(x2 % 2 != 0){
        x1++; 
        x2--; 
    }

    return 1 + numRondas(x1 / 2, x2 / 2);
}


void solve(){
    int n, r; cin >> n >> r; 

    int numeros = pow(2, n); 

    int res = log2(numeros - r + 1);
    res++; 

    cout << min(n, res) << endl;  
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