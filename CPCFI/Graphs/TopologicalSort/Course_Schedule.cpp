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

    int n, m; cin >> n >> m;

    vector<vi> dag(n+1); 

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b; 
        dag[a].pb(b);
    }

    vi ady(n+1);

    for(int i = 1; i <= n; i++){
        for(auto v: dag[i])
            ady[v]++; 
    }

    priority_queue<int> pq; 

    for(int i = 1; i <= n; i++){
        if(ady[i] == 0)
            pq.push(i); 
    }

    vi res; 

    while(!pq.empty()){
        int u = pq.top(); pq.pop(); 
        res.pb(u);

        for(auto v: dag[u]){
            ady[v]--; 

            if(ady[v] == 0)
                pq.push(v); 
        }
    }

    if(sz(res) != n){
        cout << "IMPOSSIBLE" << endl; 
        return; 
    }

    for(auto x: res)
        cout << x << " ";
    
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