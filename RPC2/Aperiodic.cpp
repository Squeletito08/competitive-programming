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


ll log_a_to_base_b(ll a, ll b)
{
    return log2(a) / log2(b);
}

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll respuesta(ll n, ll k){
    ll x = log_a_to_base_b((k-1)*n + 1, k); 

    //cout << " x -> " << x << endl; 

    if(x == 0) return 0; 

    if(x-1 >= k) return n - binpow(k, k); 

    ll nn = (binpow(k, x) - 1 ) / (k - 1); 
    ll r = (binpow(k, x-1) - 1 ) / (k - 1); 
    ll rr=0, nnn=0;
    for(int i=nn; i <= n; i +=nn) {
        rr += r;
        nnn += nn;
    }
    //cout << " n " << n << "  nn " << nn << "  r " << r << endl; 
    return rr + respuesta(n-nnn, k); 
}

void solve(){
    ll n, k, resp; cin >> n >> k; 

    if(n <= k) resp = 0;
    else resp =respuesta(n, k);
    cout << resp << endl; 
    
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