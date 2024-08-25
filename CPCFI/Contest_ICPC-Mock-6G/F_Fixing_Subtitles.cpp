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

string aumHora(string t, double dif){
    int horas = stoi(t.substr(0, 2)); 

    int min = stoi(t.substr(3,2));

    int sec = stoi(t.substr(6, 2)); 

    int milSec = stoi(t.substr(9, 2)); 

    int extraSec = (int)dif; 

    int extraMilSec = (dif - extraSec) * 1000; 

    sec += extraSec; 

    milSec += extraMilSec; 
    
}


void solve(){
    int n; 
    double dif; 

    cin >> n; 
    cin >> dif; 

    vector<vector<string>> sub(n, vector<string>()); 

    for(int i = 0; i < n; i++){

        for(int j = 0; j < 4; i++){
            string s; 
            cin >> s; 

            // string x = s; 

            // auto end_pos = remove(x.begin(), x.end(), ' ');
            // x.erase(end_pos, x.end());

            // if(x == ""){
            //     break; 
            // }
            sub[i].push_back(s); 
        }
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