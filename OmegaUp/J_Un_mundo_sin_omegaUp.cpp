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

bool comp(pair<string, int> a, pair<string, int> b){

    int a_int = a.se; 
    int b_int = b.se; 

    if(a_int > b_int){
        return true; 
    }

    if(a_int < b_int){
        return false;
    }

    string a_s = a.fi; 
    string b_s = b.fi;

    return a_s < b_s; 
}


void solve(){

    int n; 
    cin >> n; 

    unordered_map<string, unordered_map<char, int>> info; 

    while(n--){
        string s; 
        cin >> s; 

        char plm; 
        cin >> plm; 

        int pun; 
        cin >> pun; 

        if(!info[s].count(plm)){
            info[s].insert({plm, pun});
        }
        else{
            if(pun > info[s][plm]){
                info[s][plm] = pun;
            }
        }
    }

    unordered_map<string, int> puntaje; 

    for(const auto& x: info){
        for(const auto& y: x.se){
            puntaje[x.fi] += y.se;
        }
    }

    vector<pair<string, int>> puntaje_vec(all(puntaje));

    sort(all(puntaje_vec), comp);

    for(int i = 0; i < 4; i++){
        cout << puntaje_vec[i].fi << "\n"; 
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
