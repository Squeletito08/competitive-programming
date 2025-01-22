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

bool valido(int i, int j, int n){
    return i >= 0 && i < n && j >= 0 && j < n; 
}

bool esCruz(vector<vector<char>>& m, int i, int j, int n){

    return valido(i, j, n) && valido(i-1, j, n) && valido(i+1, j, n) && valido(i, j+1, n) && valido(i, j-1, n) 
     && m[i][j] == '#' && m[i-1][j] == '#' && m[i+1][j] == '#' && m[i][j-1] == '#' && m[i][j+1] == '#'; 
}



void solve(){
    int n; 
    cin >> n; 
    
    vector<vector<char>> mtz (n, vector<char>(n, '.')); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mtz[i][j]; 
        }
    }

    int ctd = 0; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mtz[i][j] == '#'){
                ctd++; 
            }
        }
    }

    if(ctd % 5 != 0){
        cout << "NO\n"; 
        return; 
    }

    int numCruz = ctd / 5; 

    int c = 0; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(esCruz(mtz, i, j, n)){
                c++; 
                mtz[i-1][j] = '.'; 
                mtz[i][j-1] = '.'; 
                mtz[i][j] =  '.';
                mtz[i+1][j] = '.'; 
                mtz[i][j+1] = '.';   
            }
        }
    }

    if(c == numCruz){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    cout << "\n"; 


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