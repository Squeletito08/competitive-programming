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

    int n; 
    cin >> n; 
    string s; 
    cin >> s; 

    set<char> dif; 

    for(int i = 0; i < n; i++){
        dif.insert(s[i]); 
    }

    vector<char> sVec; 

    for(auto x: dif){
        sVec.pb(x);
    }

    unordered_map<char, char> map; 

    int i = 0; 
    int j = sVec.size() - 1; 

    while(i <= j){
        map[sVec[i]] = sVec[j];
        map[sVec[j]] = sVec[i];
        i++; 
        j--; 
    }

    string res = ""; 

    for(int i = 0; i < n; i++){
        res += map[s[i]];
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