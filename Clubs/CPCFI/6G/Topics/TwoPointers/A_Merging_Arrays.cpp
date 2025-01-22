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
    vi a(n); 
    vi b(m);

    read_vi(a, n); 
    read_vi(b, m); 

    int i = 0; 
    int j = 0; 

    while(i < n && j < m){
        if(a[i] < b[j]){
            cout << a[i] << " "; 
            i++; 
        }
        else{
            cout << b[j] << " "; 
            j++; 
        }
    }

    while(i < n){
        cout << a[i] << " "; 
        i++; 
    }

    while(j < m){
        cout << b[j] << " "; 
        j++; 
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