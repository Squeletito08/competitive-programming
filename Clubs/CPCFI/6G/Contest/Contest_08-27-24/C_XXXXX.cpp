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
    int n, x; 
    cin >> n >> x; 

    vi nums(n); 

    read_vi(nums, n);

    int contador = 0; 
    int max = 0; 
    int suma = 0; 

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if((suma + nums[j]) % x != 0){
                suma += nums[j]; 
                contador++; 
            }
            else{
                break; 
            }

            if(contador > max){
                max = contador; 
            }
        }
        suma = 0; 
        contador = 0; 
    }

    if(max == 0){
        cout << -1; 
    }
    else{
        cout << max; 
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