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

ii binS(vi& pm, int l, int r, int x){

    int ctd = 0; 
    int mitad = 0; 
    while((r-l != 1) && l <= r){
        ctd++; 
        mitad = l + (r-l)/2; 

        if(pm[mitad] == x){
            return {mitad, ctd}; 
        }

        if(pm[mitad] <= x){
            l = mitad; 
        }
        else{
            r = mitad; 
        }
    }

    return {mitad, ctd}; 
}


void solve(){
    int n, x; 
    cin >> n >> x; 

    vi pm(n); 
    read_vi(pm, n); 

    auto p = binS(pm, 0, n, x); 

    int fin = ceil(log2(n)); 

    if(pm[p.fi] == x && p.se == fin){
        cout << 0 << "\n"; 
        return;  
    }

    if(pm[p.fi] != x){

        int j = 0; 

        for(int i = 0; i < n; i++){
            if(pm[i] == x){
                j = i; 
                break; 
            }
        }

        cout << 1; 
        cout << j << " " << p.fi << "\n"; 
        return; 
    }

    cout << 2 << "\n";
    cout << 1 << " " << p.fi + 1 << "\n"; 
    swap(pm[p.fi], pm[0]); 

    p = binS(pm, 0, n, x); 

    cout << 1 << " " << p.fi + 1 << "\n";    
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