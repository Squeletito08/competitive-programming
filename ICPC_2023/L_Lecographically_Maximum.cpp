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

    vi bits(32, 0); 

    for(int i = 0; i < n; i++){
        bitset<32> x(nums[i]); 

        for(int j = 0; j < 32; j++){
            if(x[j])
                bits[j]++; 
        }
    }

    vi res(n, 0); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++){
            int k = (1 << j); 

            if(bits[j]){
                res[i] |= k; 
                bits[j]--; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << res[i] << " "; 
    }
    cout << "\n"; 
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