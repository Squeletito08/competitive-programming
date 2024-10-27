#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
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


bool bus(vector<vi>& graf, int n){
    int a = 0, b = 0; 

    for(int i = 1; i <= n; i++){
        if(sz(graf[i]) == 1){
            a++; 
        }

        if(sz(graf[i]) == 2){
            b++; 
        }
    }

    return a == 2 && b == n - 2; 
}


bool ring(vector<vi>& graf, int n){
    int b = 0; 

    for(int i = 1; i <= n; i++){
        if(sz(graf[i]) == 2){
            b++; 
        }
    }

    return b == n; 
}

bool star(vector<vi>& graf, int n){
    int a = 0, b = 0; 

    for(int i = 1; i <= sz(graf); i++){
        if(sz(graf[i]) == 1){
            a++; 
        }

        if(sz(graf[i]) == n - 1){
            b++; 
        }
    }

    return a == n - 1 && b == 1; 
}


void solve(){
    int n, m; cin >> n >> m; 

    vector<vi> graf(n+1); 

    for(int i = 1; i<= m; i++){
        int a, b; cin >> a >> b; 
        graf[a].pb(b); 
        graf[b].pb(a); 
    }

    if(bus(graf, n)){
        cout << "bus topology" << endl; 
        return;
    }
    cout << endl; 

    if(ring(graf, n)){
        cout << "ring topology" << endl; 
        return;
    }

    cout << endl; 

    if(star(graf, n)){
        cout << "star topology" << endl; 
        return;
    }

    cout << "unknown topology" << endl; 
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