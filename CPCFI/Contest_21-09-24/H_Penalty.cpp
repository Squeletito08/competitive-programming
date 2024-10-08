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

    int n = s.size(); 

    string t1 = s; 
    string t2 = s; 

    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0 && s[i] == '?'){
            t1[i] = '1';
        }
        if(i % 2 != 0 && s[i] == '?'){
            t1[i] = '0';
        }
    }

    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0 && s[i] == '?'){
            t2[i] = '0';
        }
        if(i % 2 != 0 && s[i] == '?'){
            t2[i] = '1';
        }
    }

    int j1 = 0;
    int j2 = 0; 

    int ctd1 = 5; 
    int g1 = 0; 


    int ctd2 = 5; 
    int g2 = 0; 

    while( ((ctd2 + g2 >= g1) || (ctd1 + g1 >= g2)) && j1 < n){

        if(j1 % 2 == 0){
            if(t1[j1] == '1'){
                g1++; 
            }
            ctd1--;
        }
        else{
            if(t1[j1] == '0'){
                g2++; 
            }
            ctd2--; 
        }

        j1++; 


    }

    while( ((ctd2 + g2 >= g1) || (ctd1 + g1 >= g2)) && j2 < n){

        if(j2 % 2 == 0){
            if(t2[j2] == '1'){
                g1++; 
            }
            ctd1--; 
        }
        else{
            if(t2[j2] == '0'){
                g2++; 
            }
            ctd2--; 
        }

        j2++; 
    }

    cout << min(j1, j2) << "\n"; 

    
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