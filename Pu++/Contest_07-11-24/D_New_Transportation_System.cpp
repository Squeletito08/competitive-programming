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


void bfs(int inicio, vector<bool>& vis, vector<vi>& graf){
    queue<int> cola; 
    cola.push(inicio); 

    while(!cola.empty()){
        int u = cola.front(); 
        cola.pop(); 
        vis[u] = 1; 

        for(auto v: graf[u]){
            if(!vis[v]){
                vis[v] = 1; 
                cola.push(v); 
            }
        }
    }
}


void solve(){
    int n, t; cin >> n >> t; 

    vector<bool> vis (n+1); 
    
    vector<vi> graf(n+1, vector<int>()); 

    for(int i = 1; i <= n-1; i++){
        int x; cin >> x; 
        graf[i].pb(i + x); 
    }

    bfs(1, vis, graf);


    if(vis[t]){
        cout << "YES";
    }
    else{
        cout << "NO";
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