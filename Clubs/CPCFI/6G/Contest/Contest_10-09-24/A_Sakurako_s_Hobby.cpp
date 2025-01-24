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

vector<ii> graf; 
set<int> recorrido; 
vector<bool> vis; 

int bfs(int sta){
    queue<int> cola; 
    cola.push(sta);
    int ctd = 0;  

    while(!cola.empty()){
        int act = cola.front(); 
        cola.pop(); 

        auto nodo = graf[act]; 


        recorrido.insert(act); 
        vis[act] = 1; 

        if(nodo.se == 0){
            ctd++; 
        }
        
        auto sig = nodo.fi; 

        if(!recorrido.count(sig)){
            cola.push(sig); 
        }
    }

    return ctd; 
}


void solve(){
    int n; 
    cin >> n;

    graf.resize(n+1); 
    vis.resize(n+1, 0); 

    for(int i = 1; i <= n; i++){
        int a; 
        cin >> a; 
        graf[i] = {a, 0};
    }

    string s; cin >> s; 

    for(int i = 1; i <= (int)s.size(); i++){
        if(s[i-1] == '0'){
            graf[i].se = 0; 
        }
        else{
            graf[i].se = 1; 
        }
    }
    vector<int> res(n+1); 

    for(int i = 1; i <= n; i++){
        int x = 0; 

        if(vis[i] == 0){
            x = bfs(i); 
        }

        for(auto y: recorrido){
            res[y] = x; 
        }

        recorrido.clear(); 
    }

    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    recorrido.clear(); 
    for(int i = 1; i <= n; i++){
        vis[i] = 0; 
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