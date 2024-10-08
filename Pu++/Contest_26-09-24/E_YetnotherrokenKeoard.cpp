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
    string s; 
    cin >> s; 

    stack<int> up; 
    stack<int> lw; 

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'b'){
            if(!lw.empty()){
                int j = lw.top(); 
                lw.pop(); 
                s[j] = '.'; 
            }
            s[i] = '.';
            continue; 
        }

        if(s[i] == 'B'){
            if(!up.empty()){
                int j = up.top(); 
                up.pop();                 
                s[j] = '.';
            }
            s[i] = '.';
            continue; 
        }

        if(isupper(s[i])){
            up.push(i); 
        }
        else{
            lw.push(i);
        }
    }

    string res = "";

    for(int i = 0; i < s.size(); i++)
        if(s[i] != '.')
            res += s[i];

    cout << res << "\n"; 
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