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

    while(true){
        int n; 
        cin >> n;

        if(n == 0)
            return; 

        vi nums(n); 
        read_vi(nums, n); 

        vi res; 

        int x_or = nums[0]; 
        res.pb(nums[0]); 

        for(int i = 1; i < n; i++){
            int x = x_or ^ nums[i];
            res.pb(x); 
            x_or ^= x; 
        }

        for(auto x: res){
            cout << x << " ";
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