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
            lab[i][j] = x;
        }
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