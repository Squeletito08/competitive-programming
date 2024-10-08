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

    vi nums(n);
    read_vi(nums, n); 

    int c1 = 0; 
    int c2 = 0; 

    for(int i = 0; i < n; i++){
        if(nums[i] == 1){
            c1++; 
        }
        else{
            c2++; 
        }
    }

    if( (c2 % 2 == 0 && c1 % 2 == 0) || (c2 % 2 != 0 &&  c1 >= 2 && c1 % 2 == 0)){
        cout << "YES\n"; 
        return; 
    }

    cout << "NO\n"; 
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