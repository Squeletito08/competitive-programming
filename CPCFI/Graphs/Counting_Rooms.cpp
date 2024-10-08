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

int n, m; 


void solve(){

    cin >> n >> m; 

    vector<vector<char>> room(n+2, vector<char>(m+2, '#')); 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> room[i][j];
        }
    }

    int ctd = 0; 

    stack<ii> pila; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(room[i][j] == '.'){
                ctd++; 

                pila.push({i, j}); 

                while(!pila.empty()){
                    auto x = pila.top(); 
                    pila.pop(); 

                    int a = x.fi; 
                    int b = x.se; 

                    room[a][b] = '#'; 

                    if(room[a+1][b] == '.'){
                        pila.push({a+1, b}); 
                    }

                    if(room[a-1][b] == '.'){
                        pila.push({a-1, b}); 
                    }

                    if(room[a][b-1] == '.'){
                        pila.push({a, b-1});
                    }

                    if(room[a][b+1] == '.'){
                        pila.push({a, b+1}); 
                    }
                }



            }
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