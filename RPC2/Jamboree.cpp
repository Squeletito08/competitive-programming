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


void solve(){
    int n, m; cin >> n >> m; 

    vi items(n); 
    read_vi(items, n); 

    sort(all(items), greater<>()); 

    vi scouts(m);

    for(int i = 0; i < m; i++){
        scouts[i] += items[i]; 
    } 

    vi resto; 

    for(int i = m; i < n; i++){
        resto.pb(items[i]); 
    }

    sort(all(resto), greater<>()); 

    int i = 0; 
    int j = m-1; 
    while(i < sz(resto)){
        scouts[j] += resto[i]; 
        i++; 
        j--; 
    }

    int max = scouts[0]; 

    for(int i = 0; i < m; i++){
        if(scouts[i] > max){
            max = scouts[i];
        }
    }

    cout << max << endl; 
    
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