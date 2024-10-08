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
    int n, q; 
    cin >> n >> q; 

    string a, b; 
    cin >> a >> b; 

    vi pref(n+1, 0);

    unordered_set<char> aS; 
    unordered_set<char> bS; 

    for(int i = 0; i < n; i++){

        char aC = a[i]; 
        char bC = b[i]; 

        if(aC != bC){
            aS.insert(aC); 
            bS.insert(bC); 

            if(aS.count(bC)){
                aS.erase(bC); 
                bS.erase(bC); 
            }
            
            if(bS.count(aC)){
                bS.erase(aC); 
                aS.erase(aC); 
            }
        }

        pref[i+1] = (aS.size() + bS.size()) / 2;  
    } 
    

    while(q--){
        int i, j; 
        cin >> i >> j; 

        int res = pref[j-1] - (pref[i-1]);

        cout << res << "\n"; 
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