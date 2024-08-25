#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long int ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}


void imprime(ll n){
    if(n == 1){
        cout << "(2)"; 
        return; 
    }
    if(n == 2){
        cout << "(2)^2"; 
        return; 
    }

    if(n % 2 == 0){
        cout << "(";
        imprime(n/2); 
        cout << ")^2"; 
    }
    else{
        cout << "(2*"; 
        imprime(n-1); 
        cout << ")"; 
    }
    return; 
}



void solve(){
    ll k; 
    cin >> k; 

    if(k == 1)
        cout << "2";
    else
        imprime(k); 


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