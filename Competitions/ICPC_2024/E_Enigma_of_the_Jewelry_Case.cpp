#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}


void solve(){
    int n; 
    cin >> n; 

    vector<vi> m(n, vi(n, 0)); 

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j]; 

    vi res; 

    res.pb(m[0][0]); 
    res.pb(m[0][n-1]); 
    res.pb(m[n-1][n-1]); 
    res.pb(m[n-1][0]); 

    int min = res[0]; 
    int pos = 0; 

    for(int i = 0; i < res.size(); i++){
        if(res[i] < min){
            min = res[i]; 
            pos = i; 
        }
    }

    cout << pos << endl; 
    
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