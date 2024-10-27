#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}


vector<vector<int>> graf; 
vector<bool> vis; 

void bfs(int inicio){

    if(vis[inicio]){
        return; 
    }

    queue<int> cola; 
    cola.push(inicio); 

    while(!cola.empty()){
        int sig = cola.front(); 
        cola.pop();

        vis[sig] = 1; 

        for(auto vec: graf[sig]){
            if(!vis[vec]){
                vis[vec] = 1; 
                cola.push(vec); 
            }
        }
    }
}

void solve(){
    int n; 
    cin >> n; 

    graf.resize(n+1); 
    vis.resize(n+1, 0); 

    for(int i = 1; i <= n; i++){
        int a; cin >> a; 
        graf[i].pb(a); 
        graf[a].pb(i);
    }

    

    int ctd = 0; 

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            bfs(i);
            ctd++; 
        }
    }

    cout << ctd << endl; 
    
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