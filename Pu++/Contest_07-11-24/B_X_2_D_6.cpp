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

void solve(){
    ll x; cin >> x;

    if(x == 1){
        cout << 0 << endl; 
        return;
    }

    ll num2 = 0; 
    ll num3 = 0; 

    while((x % 2 == 0) || (x % 3 == 0)){
        if(x % 2 == 0){
            num2++; 
            x /= 2; 
        }

        if(x % 3 == 0){
            num3++; 
            x /= 3; 
        }
    }

    if(x != 1 || num2 > num3){
        cout << -1 << endl; 
        return; 
    }

    ll maximo = max(num2, num3); 

    ll ctd = abs(num2 - num3) + maximo; 

    cout << ctd << endl;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    ll t = 1; 
    cin >> t; 

    while(t--){
        solve(); 
    }

    return 0; 
}