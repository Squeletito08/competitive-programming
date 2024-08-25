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

    sort(rall(nums)); 

    int suma = nums[0]; 

    for(int i = 1; i < n; i++){
        if(suma == 0){
            cout << "NO\n"; 
            return;
        }
        suma += nums[i];
    }


    cout << "YES\n"; 

    for(int i = 0; i < n; i++){
        cout << nums[i] << " "; 
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