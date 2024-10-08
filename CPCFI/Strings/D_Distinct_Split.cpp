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

    string s; 
    cin >> s; 

    vi a(n); 
    vi b(n); 

    unordered_set<char> dif; 
    int ctd = 0; 

    for(int i = 0; i < n; i++){
        if(!dif.count(s[i])){
            ctd++;
        }
        a[i] = ctd; 
        dif.insert(s[i]);
    }

    
    dif.clear();

    ctd = 0; 
    
    for(int i = n-1; i >= 0; i--){
        if(!dif.count(s[i])){
            ctd++;
        }
        b[i] = ctd; 
        dif.insert(s[i]);
    }


    int max = 0; 


    for(int i = 0; i < n-1; i++){
        if(a[i] + b[i+1] > max)
            max = a[i] + b[i+1];
    }

    cout << max <<  "\n"; 
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