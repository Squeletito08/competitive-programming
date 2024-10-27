#include <bits/stdc++.h>
using namespace std; 

#define INF INT_MAX
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}

class Segment_tree{
    public :
    vll t ;
 
    Segment_tree(int n = 1e5+10){
        t.assign(n*4,INF) ;
    }
 
    void update(int node, int index , int tl , int tr, int val){
        if(tr < index || tl > index) return ;
        if(tl == tr){
            if(t[node] == 0)
              return; 
            t[node] += val;
        }
        else{
            int mid = tl + ((tr-tl)>>1) ;
            int lft = (node << 1) ;
            int rght = lft + 1;
 
            update(lft,index,tl,mid,val) ;
            update(rght,index,mid+1,tr,val) ;
            t[node] += val;
        }
 
    }
 
    ll query(int node , int l , int r , int tl , int tr){
        if(tl > r || tr < l) return 0;
        if(tl == l && tr == r){
            return t[node];
        }
        else{
            int mid = tl + ((tr-tl)>>1) ;
            int lft = (node << 1) ;
            int rght = lft + 1;

            if(l >= tl && r <= mid){
              return query(lft, l, r, tl, mid); 
            }

            if(l >= (mid + 1) && r <= tr){
              return query(rght, l, r, mid+1, tr); 
            }

            return query(lft, l, mid, tl, mid) + query(rght, mid+1, r, mid + 1, tr); 
        }
    }
 
    ll build(vi &v, int node , int tl , int tr){
        if(tl == tr){
            t[node] = v[tl];
            return v[tl]; 
        }
        else{
            int mid = tl + ((tr - tl) >> 1);
            int lft = (node << 1);
            int rght = lft + 1;

            build(v,lft,tl,mid);
            build(v,rght,mid+1,tr);
            t[node] = t[lft] + t[rght];
            return t[node]; 
        }
    }
};


void solve() {
    int n, q; 
    cin >> n >> q; 

    vi v(n, 1); 

    Segment_tree seg(n);
    seg.build(v, 1, 0, n-1); 

    while(q--){
        char c; cin >> c; 

        if(c == 'A'){
          int a, b; cin >> a >> b; 
          cout << seg.query(1, a-1, b-1, 0, n-1) << "\n"; 
        }

        if(c == 'R'){
          int a; cin >> a; 
          seg.update(1, a-1, 0, n-1, -1); 
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