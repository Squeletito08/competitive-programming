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
    ll n; 
    cin >> n; 

    vll nums(n); 
    read_vll(nums, n); 

    vector<char> str(n); 

    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    vll prefix(n+1, 0); 

    for(int i = 1; i < n+1; i++){
        prefix[i] = prefix[i-1] + nums[i-1]; 
    }

    ll sum = 0; 

    ll l = 0; 
    ll r = n-1; 


    while(l <= r){
        if(str[l] == 'L' && str[r] == 'R'){
            sum += prefix[r+1] - prefix[l]; 
            l++; 
            r--; 
            continue; 
        }

        if(str[l] != 'L'){
            l++;
        }

        if(str[r] != 'R'){
            r--; 
        }
    }

    cout << sum << "\n"; 
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