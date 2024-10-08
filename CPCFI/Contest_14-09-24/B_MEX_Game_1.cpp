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
    int x; 
    cin >> n; 

    multiset<int> game; 

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        game.insert(x); 
    }


    auto it = game.begin(); 
    game.erase(it); 

    vector<int> c; 

    c.pb(*it); 

    bool alice = false; 


    while(it != game.end()){

        int f = c[c.size()-1]; 
        it = game.upper_bound(f); 

        if(it != game.end()){
            if(alice){
                c.pb(*it);
            }
            game.erase(it); 
        }

        alice = !alice; 
    }


    int mex = 0; 

    for(int i = 0; i < c.size(); i++){
        if(mex == c[i]){
            mex++; 
        }
        else{
            break; 
        }
    }

    cout << mex << endl; 


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