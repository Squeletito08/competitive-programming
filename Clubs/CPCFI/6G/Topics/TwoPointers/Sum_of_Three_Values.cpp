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
    ll n, x; 
    cin >> n >> x; 

    vector<pair<ll, int>> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i].fi; 
        nums[i].se = i; 
    }


    unordered_map<int, int> map; 

    for(int i = 0; i < n; i++){
        map[nums[i].fi] = i; 
    }

    sort(all(nums)); 

    int i = 0; 
    int j = 0; 
    int k = -1; 

    int a = 0; 
    int b = 0; 
    int c = -1; 

    while(i < j){
        ll sum = nums[i].fi + nums[j].fi; 
        a = nums[i].se; 
        b = nums[j].se; 
        if(sum >= x){
            j--; 
        }
        else{
            int find = x - sum; 

            if(map.count(find) && map[find] != a && map[find] != b){
                k = map[find]; 
                break; 
            }
            i++; 
        }
    }

    if(k == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << i+1 << " " << k+1 << " " << j+1; 
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