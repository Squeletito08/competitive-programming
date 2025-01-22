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

unordered_map<char, int> puntaje(){

    unordered_map<char, int> m; 

    int j = 1; 
    for(char i = '1'; i <= '9'; i++){
        m[i] = j; 
        j++; 
    }

    j = 10; 
    for(char i = 'a'; i <= 'z'; i++){
        m[i] = j; 
        j++;
    }

    j = 10; 
    for(char i = 'A'; i <= 'Z'; i++){
        m[i] = j*2; 
        j++;
    }

    return m; 
}


void solve(){
    string ana, carolina;
    cin >> ana >> carolina; 

    unordered_map<char, int> mapa = puntaje();

    int ap = 0; 
    int cp = 0; 


    for(int i = 0; i < ana.size(); i++){
        ap += mapa[ana[i]]; 
    }

    for(int i = 0; i < carolina.size(); i++){
        cp += mapa[carolina[i]];
    }

    if(ap > cp){
        cout << "Ana " << ap;
    }
    else{
        cout << "Carolina " << cp;
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