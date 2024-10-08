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
    while(getline(cin, s)){
        int n = stoi(s); 

        unordered_map<string, string> personas; 

        for(int i = 0; i < n; i++){
            string a, b; 
            cin >> a >> b; 
            personas[a] = b; 
        }

        string inicio = ""; 

        for(const auto& x: personas){
            if(!personas.count(x.se)){
                inicio = x.se; 
                break; 
            }
        }

        unordered_map<string, string> fila;

        for(const auto& x: personas){
            fila[x.se] = x.fi;
        }

        while(true){
            cout << inicio << "\n"; 

            if(fila.count(fila[inicio])){
                inicio = fila[inicio]; 
            }
            else{
                break;
            }
        }
        cout << fila[inicio] << "\n"; 
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