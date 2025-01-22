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

void setIO(string s = "") {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


void solve(){

    int n; 
    cin >> n; 

    string a, b; 
    cin >> a; 
    cin >> b; 

    int contador = 0; 

    int i = 0; 
    
    while(i < a.size()){
        if(a[i] != b[i]){
            contador++; 
            while(a[i] != b[i]){
                i++; 
            }
        }
        i++; 
    }

    cout << contador << "\n"; 
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    setIO("breedflip");

    int t = 1; 

    while(t--){
        solve(); 
    }

    return 0; 
}

