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
    string m, n; 
    cin >> m >> n; 

    vector<ii> pos; 

    for(int i = 0; i < m.size(); i++){
        if(m[i] == '*'){
            pos.pb({i, 1}); 
        }
    }

    for(int i = 0; i < n.size(); i++){
        if(n[i] == '*'){
            pos.pb({i, 2});
        }
    }

    for(int i = 0; i < pow(2, pos.size()); i++){
        string m_aux = m; 
        string n_aux = n; 

        for(int j = 0; j < pos.size(); j++){
            int k = (1 << j); 

            if(i & k){
                if(pos[j].se == 1){
                    m_aux[pos[j].fi] = '1';
                }
                else{
                    n_aux[pos[j].fi] = '1';
                }
            }
            else{
                if(pos[j].se == 1){
                    m_aux[pos[j].fi] = '0';
                }
                else{
                    n_aux[pos[j].fi] = '0';
                }  
            }
        }

        int k = stoi(n_aux, nullptr, 2); 


        int num = 0; 
        int mod = 1; 

        reverse(m_aux.begin(), m_aux.end()); 

        if(m_aux[0] == '1'){
            num += 1; 
        }

        mod = mod % k; 

        for(int i = 1; i < m_aux.size(); i++){
            mod *= 2; 
            mod = mod % k; 

            if(m_aux[i] == '1'){
                num += mod; 
            }
        }

        reverse(m_aux.begin(), m_aux.end());

        if(num % k == 0){
            cout << m_aux << "\n";
            return; 
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