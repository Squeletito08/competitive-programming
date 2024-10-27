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

int bin1(vector<ii>& rect, int hs, int ws){

    int res = -1; 
    int l = 0; 
    int r = rect.size() -1; 

    while(l <= r){
        int mid = l + (r-l)/2; 
        
        cout << mid << endl;

        cout << "l -> " << l << endl; 
        cout << "r -> " << r << endl; 
        cout << "res -> " << res << endl; 

        if(hs < rect[mid].f && ws < rect[mid].s){
            res = mid; 
            r = mid - 1; 
        }

        else if(hs > rect[mid].f || ws > rect[mid].s){
            r = mid - 1; 
        }
        else if(rect[mid].f > hs || rect[mid].s > ws){
            l = mid + 1; 
        }
    }

    return res; 
}

int bin2(vector<ii>& rect, int hb, int wb, int a){

    int res = -1; 
    int l = a; 
    int r = rect.size() -1; 

    while(l <= r){
        int mid = l + (r-l)/2; 

        if(hb > rect[mid].f && wb > rect[mid].s){
            res = mid; 
            l = mid + 1; 
            continue; 
        }

        if(hb > rect[mid].f || wb > rect[mid].s){
            l = mid + 1; 
        }
        else if(rect[mid].f > hb || rect[mid].s > wb){
            r = mid - 1; 
        }
    }

    return res; 
}


void solve(){
    int n, q; cin >> n >> q; 

    vector<ii> rect(n); 

    vector<ll> pref(n+1); 

    for(int i = 0; i < n; i++){
        int h, w; cin >> h >> w; 
        rect[i].f = h; 
        rect[i].s = w; 
    }

    for(int i = 1; i < n+1; i++){
        int area = rect[i-1].f * rect[i-1].s; 
        pref[i] = pref[i-1] + area; 
    }

    sort(all(rect)); 



    while(q--){
        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb; 

        int a = bin1(rect, hs, ws); 

        if(a == -1){
            cout << 0 << endl; 
            continue; 
        }

        int b = bin2(rect, hb, wb, a); 

        if(b == -1){
            cout << 0 << endl; 
            continue; 
        }

        cout << pref[b] - pref[a-1] << endl; 
    }


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