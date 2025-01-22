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
    int n; 
    cin >> n; 

    vi a(n); 
    read_vi(a, n); 

    int min = a[0]; 
    int max = a[0];
    
    for(int i = 0; i < n; i++){
        if (a[i] < min){
            min = a[i];
        }

        if(a[i] > max){
            max = a[i]; 
        }
    }

    int res = (max - min) * (n-1); 
    
    cout << res << endl;  
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