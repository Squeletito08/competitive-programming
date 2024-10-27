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
    int w, d, h; 
    cin >> w >> d >> h; 

    int a, b, f, g; 
    cin >> a >> b >> f >> g; 

    int res = h; 

    int op1 = 0, op2 = 0, op3 = 0, op4 = 0; 

    op1 += g + b + abs(f-a); 
    op2 += (d-g) + (d - b) + abs(f-a); 

    op3 += f + a + abs(g-b); 
    op4 += abs(w-f) + abs(w-a) + abs(g-b); 

    int mm = min(min(op1, op2), min(op3, op4)); 
    res += mm; 

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