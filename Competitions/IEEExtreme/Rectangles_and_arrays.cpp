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
    ll n, x;  cin >> n >> x; 
    vll nums(n+1); 
    multiset<ll> ms;

    for(int i = 1; i <= n; i++){
        int x; cin >> x; 
        ms.insert(x); 
        nums[i] = x; 
    }

    ll l = 1; 
    ll r = n; 

    ll area = 0; 

    while(l < r){

        auto it1 = ms.begin(); 
        ms.erase(it1); 
        auto it2 = ms.begin(); 
        ms.insert(*it1); 

        if(it2 == ms.end())
            it2 = it1; 


        ll h = min(*it2, x);
        area = max(area, (r-l+1)*h);
        

        if(nums[l] < nums[r]){
            auto t = ms.find(nums[l]); 
            ms.erase(t);
            l++; 
        }
        else{
            auto t = ms.find(nums[r]); 
            ms.erase(t); 
            r--; 
        }
    }

    cout << area << endl; 
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