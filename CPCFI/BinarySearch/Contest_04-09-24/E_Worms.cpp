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


int binary(vector<pair<int, int>>& nums, int l, int r, int buscar){
    while(l <= r){
        int mitad = l + (r-l)/2; 

        auto inter = nums[mitad]; 

        if(buscar >= inter.fi && buscar <= inter.se){
            return mitad; 
        }

        if(buscar < inter.fi){
            r = mitad-1; 
        }

        if(buscar > inter.se){
            l = mitad+1; 
        }
    }

    return -1; 
}


void solve(){
    int n; 
    cin >> n; 
    vi nums(n); 
    read_vi(nums, n); 

    int m; 
    cin >> m; 
    vi q(m); 
    read_vi(q, m);

    vector<pair<int, int>> inter(n); 

    inter[0] = {1, nums[0]}; 

    for(int i = 1; i < n; i++){
        int anterior = inter[i-1].se; 
        inter[i] = {anterior+1, nums[i]+anterior}; 
    }

    for(int i = 0; i < m; i++){
        cout << binary(inter, 0, inter.size() - 1, q[i]) + 1 << "\n"; 
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