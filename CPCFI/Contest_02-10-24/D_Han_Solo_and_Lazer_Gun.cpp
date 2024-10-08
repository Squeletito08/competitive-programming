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
    long double n, x, y; 

    cin >> n >> x >> y; 

    set<long double> pen; 

    int ctd = 0; 
    bool mismaX = true, mismaY = true; 

    while(n--){
        long double a, b; cin >> a >> b; 

        if(a == x){
            if(mismaX){
                ctd++; 
                mismaX = false; 
            }
            continue; 
        }

        if(b == y){
            if(mismaY){
                ctd++; 
                mismaY = false; 
            }
            continue; 
        }

        long double m = (b - y) / (a - x); 

        pen.insert(m); 
    }

    cout << pen.size() + ctd << endl; 
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