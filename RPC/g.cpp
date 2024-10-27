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

long double minimo(long double a, long double b){
    if(a < b)
        return a;
    return b; 
}

long double maximo(long double a, long double b){
    if(a > b)
        return a; 
    return b; 
}


void solve(){
    ll n, l;
    cin >> n >> l;  

    vector<pair<long double, pair<long double, long double>>> dis(n); 

    for(int i = 0; i < n; i++){
        ll a, b, c; cin >> a>> b >> c; 
        dis[i].f = a; 
        dis[i].s.f = b; 
        dis[i].s.s = c; 
    }

    sort(dis.begin(), dis.end());

    vector<long double> tomas(n, l);
    vector<long double> notomas(n, l);

    long double disMin = l; 
     

    for(int i = 0; i < n; i++){
        long double x = dis[i].f;
        long double m = dis[i].s.f;
        long double d = dis[i].s.s;

        long double distancia = maximo((l-x) / m + x, tomas[i] -(m-1) * d);
        tomas[i] = distancia; 

        if(tomas[i] < disMin){
            disMin = tomas[i]; 
        }

        long double salto = x + m*d; 

        for(int j = i+1; j < n; j++){
            if(dis[j].f < salto ){
                if(tomas[j] > notomas[i]) {
                    tomas[j] = notomas[i]; 
                }
                if(notomas[j] > tomas[i]) notomas[j] = tomas[i];
            }
            else{
                if(tomas[j] > tomas[i]) tomas[j] = tomas[i];
                if(notomas[j] > notomas[i]) notomas[j] = notomas[i]; 
            }

    
        }
    }

    cout << fixed << setprecision(8) << disMin << endl;

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