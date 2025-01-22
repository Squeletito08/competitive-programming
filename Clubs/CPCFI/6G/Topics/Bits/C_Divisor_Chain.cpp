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
    int x; 
    cin >> x; 

    int mascara = 1; 

    vi nums; 
    nums.pb(x); 

    while(__builtin_popcount(x) != 1){

        if((x & ~mascara) != x){
            x &= ~mascara; 
            nums.pb(x); 
        }

        mascara = mascara << 1; 
    }

    mascara =  1 << (int)log2(x); 

    while(x != 1){
        mascara = mascara >> 1; 
        x -= mascara; 

        nums.pb(x); 
    }

    cout << nums.size() << "\n"; 
    for(auto x: nums){
        cout << x << " "; 
    }

    cout << "\n"; 
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