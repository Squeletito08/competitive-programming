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
    int n; cin >> n; 
    
    vi pref(202); 

    while(n--){
        int a, b; cin >> a >> b; 

        a += 100; 
        b += 100; 
        pref[a] += 1; 
        pref[b+1] += -1; 
    }

    for(int i = 1; i < 202; i++){
        pref[i] += pref[i-1]; 
        cout << i << " -> " << pref[i] << endl; 
    }

    int m1 = 0; 
    int m2 = 0; 

    for(int i = 1; i < 202; i++){
        if(pref[i] > m1){
            m1 = pref[i]; 
        }
    }

    int ctd = 0;
    bool isla = false;  

    for(int i = 1; i < 202; i++){

        if(pref[i] != 0 && !isla){
            ctd++; 
            isla = true; 
        }

        if(pref[i] == 0){
            isla = false; 
        }
    }

    if(ctd > 2){
        cout << -1 << endl; 
        return; 
    }


    int a = 0, b = 0; 

    for(int i = 1; i < 202; i++){
        if(pref[i] != 0){
            a = i; 
            break; 
        }
    }

    for(int i = a; i < 202; i++){
        if(pref[i] == 0){
            b = i; 
            break; 
        }
    }

    int res1 = a; 

    for(int i = a; i <= b; i++){
        if(pref[i] > pref[res1]){
            res1 = i; 
        }
    }




    for(int i = b+1; i < 202; i++){
        if(pref[i] != 0){
            a = i; 
            break; 
        }
    }

    for(int i = a; i < 202; i++){
        if(pref[i] == 0){
            b = i; 
            break; 
        }
    }

    int res2 = a; 

    for(int i = a; i <= b; i++){
        if(pref[i] > pref[res2]){
            res2 = i; 
        }
    }

    cout << res1 - 100 << " " << res2 - 100 << endl; 
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