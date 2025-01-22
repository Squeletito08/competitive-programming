#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

vi a = {0, 0, 1, -1}; 
vi b = {1, -1, 0, 0}; 

bool grado(ii u, vector<vector<char>>& grid){

    bool res = true; 

    grid[u.fi][u.se] = 'x'; 

    for(int i = 0; i < 4; i++){
        ii vec = {u.fi + a[i], u.se + b[i]}; 
        if(grid[u.fi + a[i]][u.se + b[i]] == '.'){

            if(u.fi == 1){
                if(i == 0){
                    if( !(grid[vec.fi + 1][vec.se] == 'x' && grid[vec.fi][vec.se - 1] == 'x') ){
                        res = false; 
                    }
                }
                
                if(i == 1){
                    if( !(grid[vec.fi + 1][vec.se] == 'x' && grid[vec.fi][vec.se + 1] == 'x') ){
                        res = false; 
                    }
                }

                if(i == 2){
                    if( !(grid[vec.fi - 1][vec.se] == 'x' && grid[vec.fi][vec.se + 1] == 'x' && grid[vec.fi][vec.se - 1] == 'x') ){
                        res = false; 
                    }  
                }
            }

            if(u.fi == 2){
                if(i == 0){
                    if( !(grid[vec.fi - 1][vec.se] == 'x' && grid[vec.fi][vec.se - 1] == 'x') ){
                        res = false; 
                    }
                }
                
                if(i == 1){
                    if( !(grid[vec.fi - 1][vec.se] == 'x' && grid[vec.fi][vec.se + 1] == 'x') ){
                        res = false; 
                    }
                }

                if(i == 3){
                    if( !(grid[vec.fi + 1][vec.se] == 'x' && grid[vec.fi][vec.se + 1] == 'x' && grid[vec.fi][vec.se - 1] == 'x') ){
                        res = false; 
                    }  
                }
            }
        }
    }

    grid[u.fi][u.se] = '.'; 
    return res; 
}

int grado_vec(ii u, vector<vector<char>>& grid){
    int g = 0; 

    for(int i = 0; i < 4; i++){
        if(grid[u.fi + a[i]][u.se + b[i]] == '.')
            g++;
    }

    return g; 
}


void solve(){
    int n; cin >> n; 

    vector<vector<char>> grid(4, vector<char>(n+2, 'x')); 

    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j]; 
        }
    }

    int ctd = 0; 

    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] != 'x' && grado_vec({i, j}, grid) == 3 && grado({i, j}, grid))
                ctd++; 
        }
    }

    cout << ctd << endl; 
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