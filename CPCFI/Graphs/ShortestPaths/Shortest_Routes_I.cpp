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
const ll INF = LLONG_MAX; 


vector<vector<pair<ll, ll>>> graf; 
vector<ll> dist; 

void djkstra(){
    set<pair<ll, ll>> pq; 
    dist[1] = 0;

    for(int i = 1; i < sz(dist); i++){
        pq.insert({dist[i], i});
    }

    while(!pq.empty()){
        auto [d, u] = *pq.begin();  
        pq.erase(pq.begin()); 

        if(dist[u] < d) continue; 

        for(auto &[v, w]: graf[u]){
            if(dist[u] + w < dist[v]){
                pq.erase(pq.find({dist[v], v})); 
                dist[v] = dist[u] + w; 
                pq.insert({dist[v], v}); 
            }
        }
    }
}

void solve(){

    ll n, m; cin >> n >> m; 

    graf.resize(n+1); 
    dist.resize(n+1, INF); 

    for(int i = 1; i <= m; i++){
        ll a, b, c; cin >> a >> b >> c; 
        graf[a].pb({b,c}); 
    }

    djkstra(); 

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";  
    }

    cout << endl; 

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