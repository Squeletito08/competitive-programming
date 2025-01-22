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
    vi cows(n); 

    read_vi(cows, n); 

    int v = 0; 


    for(int i = 0; i < n; i++){
        if(i == 0){
            if(i+1 < n && (cows[i] > cows[i+1])){
                v = i; 
                break; 
            }
        }

        if(cows[i] < cows[i-1]){
            v = i; 
            break; 
        }

        if(cows[i] > cows[i+1]){
            v = i+1; 
            break; 
        }

        if(i == n-1){
            if(cows[i] < cows[i-1]){
                v = i; 
                break; 
            }
        }
    }

    unordered_set<int> diferentes; 

    int correcto = 0; 

    for(int i = 0; i < n; i++){
        if(cows[v] > cows[i]){
            correcto = i+1; 
        }
    }

    for(int i = 0; i < n; i++){
        if(cows[v] < cows[i]){
            correcto = i; 
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