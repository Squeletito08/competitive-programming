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


vector<vector<char>> lab; 
vector<vector<char>> camino; 

bool bfs(ii inicio){
    queue<ii> cola; 
    cola.push(inicio);

    while(!cola.empty()){
        auto sig = cola.front(); 
        cola.pop(); 

        int i = sig.fi; 
        int j = sig.se; 

        if(lab[i][j] == 'B'){
            return true; 
        }

        if(lab[i][j] == '#'){
            continue; 
        }


        lab[i][j] = '#';
        
        cola.push({i+1, j}); 
        if(camino[i+1][j] == 'x') camino[i+1][j] = 'U'; 

        cola.push({i-1, j}); 
        if(camino[i-1][j] == 'x') camino[i-1][j] = 'D'; 

        cola.push({i, j+1}); 
        if(camino[i][j+1] == 'x') camino[i][j+1] = 'L';

        cola.push({i, j-1}); 
        if(camino[i][j-1] == 'x') camino[i][j-1] = 'R'; 
    }

    return false; 
}

string cam(ii inicio){
    queue<ii> cola; 
    cola.push({inicio.fi, inicio.se}); 

    string res = "";

    while(!cola.empty()){
        auto sig = cola.front(); 
        cola.pop(); 

        int i = sig.fi; 
        int j = sig.se;
        
        if(camino[i][j] == 'A'){
            return res; 
        }

        if(camino[i][j] == 'U'){
            res += 'D'; 
            cola.push({i-1, j});
        }

        if(camino[i][j] == 'D'){
            res += 'U';
            cola.push({i+1, j});
        }

        if(camino[i][j] == 'R'){
            res += 'L';
            cola.push({i, j+1});
        }

        if(camino[i][j] == 'L'){
            res += 'R';
            cola.push({i, j-1}); 
        }
    }

    return res; 
}

void solve(){
    int n, m; cin >> n >> m; 

    lab.resize(n+2, vector<char>(m+2, '#')); 
    camino.resize(n+2, vector<char>(m+2, 'x')); 

    ii inicio = {0, 0}; 
    ii fin = {0, 0}; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c; 
            if(c == 'A'){
                inicio.fi = i; 
                inicio.se = j; 
            }

            if(c == 'B'){
                fin.fi = i; 
                fin.se = j; 
            }
            lab[i][j] = c;
        }
    }

    bool sePuede = bfs(inicio); 

    if(!sePuede){
        cout << "NO";
    }
    else{
        camino[inicio.fi][inicio.se] = 'A';
        string res = cam(fin);
        cout << "YES" << endl; 
        reverse(res.begin(), res.end());
        cout << res.size() << endl << res;
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