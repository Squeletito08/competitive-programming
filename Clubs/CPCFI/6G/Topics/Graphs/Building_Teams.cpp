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

set<int> red; 
set<int> black; 

bool bfs(int start){


    if(red.count(start) || black.count(start)){
        return true; 
    }

    queue<int> cola; 
    cola.push(start);

    while(!cola.empty()){

        int u = cola.front(); 
        cola.pop(); 

        if(red.count(u)){
            for(auto v: graf[u]){
                if(red.count(v)){
                    return false; 
                }

                if(!black.count(v)){
                    black.insert(v);
                    cola.push(v); 
                }
            }
        }

        if(black.count(u)){
            for(auto v: graf[u]){
                if(black.count(v)){
                    return false; 
                }

                if(!red.count(v)){
                    red.insert(v);
                    cola.push(v); 
                }
            }
        }

        if(!red.count(u) && !black.count(u)){
            black.insert(u); 

            for(auto v: graf[u]){
                if(black.count(v)){
                    return false; 
                }
                if(!red.count(v)){
                    red.insert(v);
                    cola.push(v); 
                }
            }
        }
    }


    return true; 
}


void solve(){
    int n, m; cin >> n >> m; 

    graf.resize(n+1); 

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }

    bool sePuede = true; 

    for(int i = 1; i <= n; i++){
        sePuede &= bfs(i); 
    }

    if(sePuede){
        for(int i = 1; i <= n; i++){
            if(black.count(i))
                cout << 1 << " ";
            else    
                cout << 2 << " "; 
        }
    }
    else{
        cout << "IMPOSSIBLE"; 
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