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

    int n, m; 
    cin >> n; 
    cin >> m; 

    vector<vi> mtx (n+2, vi(m+2, -1)); 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mtx[i][j]; 
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int up = mtx[i][j-1]; 
            int down = mtx[i][j+1]; 
            int left = mtx[i-1][j]; 
            int right = mtx[i+1][j];

            int mx = max(max(up, down), max(left, right));

            if(mtx[i][j] > mx)
                mtx[i][j] = mx; 

            cout << mtx[i][j] << " ";
        }
        cout << "\n"; 
    }

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