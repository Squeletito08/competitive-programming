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

vi bfs(int v, vector<set<int>>& graf, vector<bool>& vis){
    queue<int> cola; 
    cola.push(v); 

    vi rec; 

    while(!cola.empty()){
        int u = cola.front(); 
        cola.pop(); 

        vis[u] = 1;
        rec.pb(u); 

        for(auto v: graf[u]){
            if(!vis[v]){
                cola.push(v); 
            }
        }
    }

    return rec; 
}

void solve(){
    int n; cin >> n; 

    vector<set<int>> graf(n+1); 
    vector<bool> vis(n+1); 

    for(int i = 1; i <= n; i++){
        int u; cin >> u; 
        graf[i].insert(u); 
        graf[u].insert(i); 
    }

    int min = 1; 
    int max = 0; 

    int ctd = 0; 
    int ctd2 = 0; 

    for(int i = 1; i <= n; i++){
        vi rec; 

        if(!vis[i]){
            rec = bfs(i, graf, vis); 
            max++; 
        }
        else{
            continue; 
        }

        bool sum = true; 

        for(auto v: rec){
            if(sz(graf[v]) == 1){
                sum = false; 
            }
        }

        if(sum)
            ctd++; 
        else
            ctd2++; 
    }

    if(ctd2 == 0){
        min = ctd; 
    }
    else{
        min = ctd + 1; 
    }

    cout << min << " " << max << endl; 

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