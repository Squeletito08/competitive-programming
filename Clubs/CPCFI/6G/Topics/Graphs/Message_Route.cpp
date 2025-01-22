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

vector<vi> graf; 
vi camino;  

void bfs(int inicio, int fin){
    queue<int> cola; 
    cola.push(inicio); 

    while(!cola.empty()){
        int u = cola.front(); 
        cola.pop(); 

        for(auto vecino: graf[u]){
            if(camino[vecino] == -1){
                cola.push(vecino); 
                camino[vecino] = u; 
            }
        }
    }
}

void solve(){

    int n, m; cin >> n >> m; 

    graf.resize(n+1); 
    camino.resize(n+1, -1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }


    bfs(1, n); 

    if(camino[n] == -1){
        cout << "IMPOSSIBLE"; 
        return; 
    }


    vector<int> res; 

    res.pb(n); 

    int actual = n; 

    while(actual != 1){
        actual = camino[actual];
        res.pb(actual); 
    }   

    reverse(all(res)); 

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

    while(t--){
        solve(); 
    }

    return 0; 
}