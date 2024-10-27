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
vector<pair<ll, ll>> dist; 

void djkstra(int n){
    set<pair<ll, ll>> pq; 
    dist[1].f = 0;

    for(auto &[v, w]: graf[1]){
        if(v == n){
            dist[1].s = max(dist[1].s, w); 
        }
    }

    cout << "arista desde 1 a n" << endl; 
    cout << dist[1].s << endl; 

    for(int i = 1; i < sz(dist); i++){
        pq.insert({dist[i].f, i});
    }

    while(!pq.empty()){
        auto [d, u] = *pq.begin();  
        pq.erase(pq.begin()); 

        for(auto &[v, w]: graf[u]){
            if(v == n){

                cout << "desde: " << u << endl; 
                cout << " w -> " << w << endl; 
                ll d = dist[u].f + w - dist[u].s + dist[u].s / 2; 

                if(d < dist[v].f){
                    pq.erase(pq.find({dist[v].f, v})); 
                    dist[v].f = d; 
                    pq.insert({dist[v].f, v}); 
                    dist[v].s = max(dist[v].s, w); 
                }
                continue; 
            }
            if(dist[u].f + w < dist[v].f){
                pq.erase(pq.find({dist[v].f, v})); 
                dist[v].f = dist[u].f + w; 
                pq.insert({dist[v].f, v}); 

                dist[v].s = max(dist[v].s, w); 
            }
        }
    }
}

void solve(){

    ll n, m; cin >> n >> m; 

    graf.resize(n+1); 
    dist.resize(n+1, pair<ll, ll>(INF, -INF)); 

    pair<int, int> arista; 
    ll w = -1; 

    for(int i = 1; i <= m; i++){
        ll a, b, c; cin >> a >> b >> c; 
        graf[a].pb({b,c}); 
    }

    djkstra(n); 

    cout << dist[n].s << endl; 

    cout << dist[n].f << endl; 
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