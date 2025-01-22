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

void solve(){
    int n; 
    cin >> n; 

    vector<vector<char>> m(n, vector<char>(2*n-1, '.')); 

    m[0][n-1] = '*'; 

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 2*n-1; j++){

            bool a = j-1 >= 0 && m[i-1][j-1] == '*'; 
            bool b = j+1 < 2*n-1 && m[i-1][j+1] == '*'; 

            if(a && !b || b && !a)
                m[i][j] = '*'; 
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n-1; j++){
            cout << m[i][j];
        }
        cout << endl; 
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
