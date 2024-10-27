#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
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
    
    string s; 

    map<string, vector<string>> mapa; 
    vector<string> parents; 
    vector<string> chil; 

    while(getline(cin, s)){
        vector<string> v; 
        v.pb(s); 
 
        stringstream ss(s);
    
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        int n = sz(v[6]); 
        if(v[6].substr(1, n-2) == "Parent Event"){
            parents.pb(s); 
            mapa[s]; 
        }
        else{
            chil.pb(s); 
        }

    }

    for(int i = 0; i < sz(chil); i++){
        string s; 

        vector<string> v; 
        stringstream ss(s);
    
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        for(auto& [key, value]: mapa){
            vector<string> v2; 
            stringstream ss2(s);
        
            while (ss2.good()) {
                string substr2;
                getline(ss, substr2, ',');
                v.push_back(substr2);
            }

        }
    }

    cout << "padres -> " << endl; 
    for(auto x: parents){
        cout << x << " "; 
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