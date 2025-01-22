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

bool bfs(int inicio, int fin){

    queue<int> cola; 
    cola.push(inicio); 

    while(!cola.empty()){
        int u = cola.front(); 
        
        cola.pop(); 

        if(u == fin){
            return true; 
        }

        for(auto vecino: graf[u]){
            cola.push(vecino); 
        }
    }

    return false; 
}

void solve(){
    int n, t; cin >> n >> t; 

    graf.resize(n+1); 

    for(int i = 1; i < n; i++){
        int x; cin >> x; 
        graf[i].pb(i + x); 
    }

    // for(int i = 1; i<= n; i++){
    //     cout << "i -> " << i << endl; 
    //     for(auto x: graf[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl; 
    // }

    bool sePuede = bfs(1, t);

    if(sePuede){
        cout << "YES";
    }
    else{
        cout << "NO";
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