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

vi bfs(int inicio, vector<vi>& graf, vector<bool>& vis){
    queue<int> cola; 
    cola.push(inicio); 

    vis[inicio] = 1; 

    vi res; 

    while(!cola.empty()){
        int u = cola.front(); 
        cola.pop(); 

        res.pb(u); 

        for(auto v: graf[u]){
            if(!vis[v]){
                cola.push(v); 
                vis[v] = 1; 
            }
        }
    }

    return res; 
}


void solve(){
    int n, m; cin >> n >> m;

    vector<vi> graf(n+1); 
    vector<bool> vis(n+1); 

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }

    vi rec = bfs(1, graf, vis); 

    // cout << "recorrido -> " << endl; 

    // for(auto x: rec){
    //     cout << x << " ";
    // }

    vi res;  

    for(int i = 0; i < n; i+=2){
        res.pb(rec[i]); 
    }

    cout << res.size() << endl; 

    for(auto x: res){
        cout << x << " ";
    }

    cout << endl; 
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