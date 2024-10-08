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
    int n, m; 
    cin >> n >> m; 

    string B = "x"; 

    for(int i = 0; i < m; i++){
        B += 'B'; 
    }

    vi nums(n); 
    read_vi(nums, n); 

    for(int i = 0; i < n; i++){
        int a = nums[i]; 
        int b = m+1-nums[i]; 

        if(a < b){
            if(B[a] == 'A'){
                B[b] = 'A';
            }
            else{
                B[a] = 'A';
            }
        }
        else{
            if(B[b] == 'A'){
                B[a] = 'A';
            }
            else{
                B[b] = 'A';
            }
        }
    }

    B = B.substr(1, B.size()-1);  
    cout << B << "\n"; 
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