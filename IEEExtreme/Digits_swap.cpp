#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
const ll MOD = 1e9+7;

bool comp(pair<char, int> a, pair<char, int> b){
    if(a.f != b.f)
        return a.f > b.f; 
    return a.s > b.s; 
}


class Compare {
    public:
       bool operator()(pair<char, int> a, pair<char, int> b){
           if(a.first != b.first){
               return a.first < b.first;
           }
           return a.second < b.second;
      }
};




void solve(){
    string str; cin >> str; 
    int n = sz(str); 
    int k; cin >> k; 

    vector<pair<char, int>> nums; 
    
    for(int i = 0; i < sz(str); i++){
        nums.pb({str[i], i}); 
    }

    sort(all(nums), comp); 


    priority_queue<pair<char, int>, vector<pair<char,int>>, Compare> pq(all(nums)); 

    int i = 0; 
    auto e = pq.top(); pq.pop(); 
    while(k && i < n && !pq.empty()){


        if(i >= e.s){
            e = pq.top(); pq.pop(); 
            continue; 
        }
            

        if(str[i] < e.f){
            pq.push({str[i], e.s}); 
            char aux = str[i]; 
            str[i] = e.f;
            str[e.s] = aux; 
            k--; 
            e = pq.top(); pq.pop(); 
        }
        i++; 
    }

    cout << str << endl; 
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