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

    set<int, greater<int>> mayusculas; 
    set<int, greater<int>> minusculas; 

    for(int i = 0; i < s.size(); i++){

        if(s[i] == 'B'){
            s[i] = '.';

            if(!mayusculas.empty()){
                auto finalMayus = mayusculas.begin(); 

                if(finalMayus != mayusculas.end()){
                    s[*finalMayus] = '.'; 
                    mayusculas.erase(finalMayus); 
                }   
            }
        }

        if(s[i] == 'b'){
            s[i] = '.'; 

            if(!minusculas.empty()){
                auto finalMinus = minusculas.begin(); 

                if(finalMinus != minusculas.end()){
                    s[*finalMinus] = '.';
                    minusculas.erase(finalMinus); 
                }
            }

        }
        
        if(s[i] != 'B' && s[i] != 'b' && s[i] != '.' && isupper(s[i])){
            mayusculas.insert(i);
        }

        if(s[i] != 'b' && s[i] != 'B' && s[i] != '.' && !isupper(s[i])){
            minusculas.insert(i); 
        }
    }

    string res = ""; 

    for(int i = 0; i < s.size(); i++){
        if(s[i] != '.')
            res += s[i]; 
    }

    cout << res << "\n"; 
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