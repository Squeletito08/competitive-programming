#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
const ll MOD = 1e9+7;


void solve(){
    string s; cin >> s; 
    int n = sz(s); 

    set<char> conj; 

    int numU = 0; 

    for(int i = 0; i < sz(s); i++){
        if(s[i] == 'U'){
            numU++; 
        }
        conj.insert(s[i]); 
    }

    if(conj.count('U') == 0){
        cout << "2 1 2 " << endl;
        cout << "2 0" << endl; 
        cout << "0 0" << endl; 
    }

    if(conj.count('L') == 0){
        cout << "3 1 2" << endl; 
        cout << "2 3" << endl; 
        cout << "0 0" << endl; 
        cout << "0 0" << endl; 
    }

    if(conj.count('R') == 0){
        cout << "3 1 3" << endl; 
        cout << "2 3" << endl; 
        cout << "0 0" << endl; 
        cout << "0 0" << endl; 
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