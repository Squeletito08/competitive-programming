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

vector<vi> graf; 
vi pesos; 
vi dp; 

int dfs(int u, int p, int ctd, int anterior){

    int res = ctd; 

    for(auto v: graf[u]){

        if(v == anterior)
            continue; 

        if(dp[v] != -1){
            dp[u] = max(dp[u], dp[v]); 
            continue; 
        }

        if(p < pesos[v]){
            int r2 = dfs(v, pesos[v], ctd+1, u); 
            int r1 = dfs(v, p, ctd, u); 
            res = max(r1, r2); 
        }
        else{
            res = max(res, dfs(v, p, ctd, u)); 
        }  

        dp[u] = max(dp[u], res); 
    }

    dp[u] = max(dp[u], ctd); 
    return dp[u];  
}

void solve(){
    int n; cin >> n; 

    pesos.resize(n+1); 
    graf.resize(n+1);
    dp.resize(n+1, -1); 

    for(int i = 1; i <= n; i++){
        cin >> pesos[i]; 
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }


    int x = 1; 
    int min = pesos[1]; 

    for(int i = 1; i <= n; i++){
        if(pesos[i] < min){
            min = pesos[i]; 
            x = i;
        }
    }

    dp[x] = 1; 
    cout << dfs(x, min, 1, 0) << endl; 
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