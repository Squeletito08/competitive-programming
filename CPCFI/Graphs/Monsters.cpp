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

vector<vector<char>> graf; 
vector<vector<char>> camino; 

struct Tipo{
    int i; 
    int j; 
    char tipo; 
}

queue<Tipo> cola; 

void bfs(){

    while(!cola.empty()){
        Tipo act = cola.front(); 
        cola.pop(); 

        if(camino[tipo.i + 1][tipo.j] == 'x'){
            Tipo x; 
            x.i = act.i + 1; 
            x.j = act.j; 
            x.tipo = act.tipo;
            cola.push(x); 
        } 
        if(camino[tipo.i - 1][tipo.j] == 'x'){
            Tipo x; 
            x.i = act.i - 1; 
            x.j = act.j; 
            x.tipo = act.tipo;
            cola.push(x); 
        }
        if(camino[tipo.i][tipo.j + 1] == 'x'){
            Tipo x; 
            x.i = act.i; 
            x.j = act.j + 1; 
            x.tipo = act.tipo;
            cola.push(x); 
        }
        if(camino[tipo.i + 1][tipo.j - 1] == 'x'){
            Tipo x; 
            x.i = act.i; 
            x.j = act.j - 1; 
            x.tipo = act.tipo;
            cola.push(x); 
        }               
    }
}

void solve(){
    int n, m; cin >> n >> m; 

    graf.resize(n+2, vector<char>(m+2, '#')); 
    camino.resize(n+2, vector<char>(m+2, 'x'));

    vector<Tipo> monst;
    
    Tipo jugador; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c; 

            Tipo t; 
            t.i = i; 
            t.j = j; 
            t.tipo = c; 

            if(c == 'M'){
                monst.pb(tipo);
            }

            if(c == 'A'){
                jugador = tipo; 
            }
        }
    }

    cola.push(jugador); 

    for(auto m: monst){
        cola.push(m); 
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