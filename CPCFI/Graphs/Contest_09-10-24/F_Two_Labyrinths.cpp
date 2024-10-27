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

vector<vector<char>> recorrido; 
vector<int> pos1 = {1, -1, 0, 0}; 
vector<int> pos2 = {0, 0, 1, -1}; 
vector<char> dir = {'D', 'U', 'R', 'L'}; 


void bfs(ii inicio, vector<vector<char>>& lab){
    queue<ii> cola; 
    cola.push(inicio); 

    while(!cola.empty()){
        auto act = cola.front(); 
        cola.pop(); 

        for(int k = 0; k < 4; k++){
            int i = pos1[k] + act.fi; 
            int j = pos2[k] + act.se; 
            char d = dir[k]; 

            if(recorrido[i][j] == '.'){
                recorrido[i][j] = d; 
                cola.push({i, j}); 
            }
        }
    }
}

string bfs_ruta(ii inicio){
    queue<ii> cola; 
    cola.push(inicio); 

    string res = ""; 

    while(!cola.empty()){
        ii act = cola.front(); 
        cola.pop();

        char c = recorrido[act.fi][act.se]; 

        if(act.fi == 1 && act.se == 1){
            return res; 
        }

        if(c == 'D'){
            cola.push({act.fi-1, act.se}); 
            res += 'D'; 
        }

        if(c == 'U'){
            cola.push({act.fi+1, act.se}); 
            res += 'U';
        }

        if(c == 'L'){
            cola.push({act.fi, act.se+1}); 
            res += 'L';
        }

        if(c == 'R'){
            cola.push({act.fi, act.se-1}); 
            res += 'R'; 
        }
    }

    return res; 
}

bool se_puede(string rec, int n, int m, vector<vector<char>>& lab){
    int i = 1; 
    int j = 1; 

    int k = 0; 

    while(k < (int)rec.size() && lab[i][j] == '.'){
        if(rec[k] == 'D'){
            i++; 
        }

        if(rec[k] == 'U'){
            i--;
        }

        if(rec[k] == 'L'){
            j--; 
        }

        if(rec[k] == 'R'){
            j++; 
        }

        k++; 
    }
    return i == n && j == m; 
}

void solve(){

    int n, m; cin >> n >> m; 

    vector<vector<char>> M(n+2, vector<char> (m+2, '#')) ; 
    vector<vector<char>> C(n+2, vector<char> (m+2, '#'));    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> M[i][j]; 
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> C[i][j]; 
        }
    }

    recorrido = M; 

    bfs({1, 1}, M); 

    if(recorrido[n][m] == '.' || recorrido[n][m] == '#'){
        cout << "NO" << endl; 
        return; 
    }

    string rec1 = bfs_ruta({n,m}); 

    recorrido = C; 

    bfs({1,1}, C); 

    if(recorrido[n][m] == '.' || recorrido[n][m] == '#'){
        cout << "NO" << endl; 
        return; 
    }

    string rec2 = bfs_ruta({n,m}); 

    reverse(rec1.begin(), rec1.end()); 
    reverse(rec2.begin(), rec2.end()); 

    bool sePuede = false; 

    sePuede |= se_puede(rec1, n, m, C); 
    sePuede |= se_puede(rec2, n, m, M); 

    if(sePuede)
        cout << "YES"; 
    else
        cout << "NO";

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