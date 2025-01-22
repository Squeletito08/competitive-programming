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
    string s; 
    cin >> s; 


    bool dos = false;
    bool tres = false; 

    int n = s.size() -1; 

    int ultimo = stoi(s.substr(n, 1)); 

    bool sePuede  = false;  

    vi res; 

    if(ultimo % 2 == 0){
        res.pb(2); 
        sePuede = true;
        dos = true; 
    }

    ll suma = 0;

    for(int i = 0; i <= n; i++){
        suma += stoi(s.substr(i, 1));
    }

    if(suma % 3 == 0){
        res.pb(3);
        sePuede = true;
        tres = true; 
    }

    int dosUltimas = 1; 
    if(s.size() >= 2){
        dosUltimas = stoi(s.substr(n-1, 2)); 
    }

    if(dosUltimas % 4 == 0){
        res.pb(4); 
        sePuede = true;
    }

    if(s[n] == '5' || s[n] == '0'){
        res.pb(5); 
        sePuede = true;
    }

    if(dos && tres){
        res.pb(6); 
    }

    if(!sePuede){
        cout << "-1"; 
    }
    else{
        for(int i = 0; i < res.size() -1; i++){
            cout << res[i] << " ";
        }
        cout << res[res.size()-1]; 
    }

    cout << "\n"; 
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