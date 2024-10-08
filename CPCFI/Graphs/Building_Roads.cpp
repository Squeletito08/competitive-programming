#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}

vector<bool> visitados; 
vector<vi> graf; 

set<int> bfs(int v){

    queue<int> cola; 

    set<int> componente; 
    if(!visitados[v]){
        componente.insert(v);
    }

    visitados[v] = 1; 
    cola.push(v); 

    while(!cola.empty()){
        int nodo = cola.front(); 
        cola.pop(); 
        for(auto u: graf[nodo]){
            if(!visitados[u]){
                visitados[u] = 1;
                cola.push(u); 
                componente.insert(u); 
            }
        }
    }

    return componente;
}


void solve(){

    int n, m; cin >> n >> m; 
    graf.resize(n+1);  

    visitados.resize(n+1); 

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }

    vector<int> comp; 

    for(int i = 1; i <= n; i++){
        set<int> s = bfs(i);
        if(!s.empty()){
            comp.pb(*s.begin()); 
        }
    }


    cout << comp.size() - 1 << "\n"; 

    int ant = comp[0]; 
    
    for(int i = 1; i < comp.size(); i++){
        cout << ant << " " << comp[i] << "\n";
        ant = comp[i]; 
    }
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