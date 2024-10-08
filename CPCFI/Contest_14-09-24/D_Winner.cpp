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

    vector<pair<string, int>> round(n); 

    for(int i = 0; i < n; i++){
        cin >> round[i].fi; 
        cin >> round[i].se; 
    }

    map<string, int> pre; 

    for(int i = 0; i < n; i++){
        string s = round[i].fi; 
        int x = round[i].se; 

        if(!pre.count(s)){
            pre[s] = x; 
        }
        else{
            pre[s] += x; 
        }
    }

    int max = pre.begin()->se; 

    for(auto const& [key, val]: pre){
        if(val > max){
            max = val; 
        }
    }

    map<string, int> game; 

    for(int i = 0; i < n; i++){
        string s = round[i].fi; 
        int x = round[i].se; 

        if(!game.count(s)){
            game[s] = x; 
        }
        else{
            game[s] += x; 
        }

        if(game[s] >= max && pre[s] == max){
            cout << s << "\n"; 
            return; 
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