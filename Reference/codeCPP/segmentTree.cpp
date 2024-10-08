#include <bits/stdc++.h>
using namespace std; 

#define INF INT_MAX
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}


// Implementación de Segment Tree para encontrar minimos 
class Segment_tree{
    public :
    vll t ;
 
    Segment_tree(int n = 1e5+10){
        t.assign(n*4,INF) ;
    }
 
    void update(int node, int index , int tl , int tr, int val){
 
        if(tr < index || tl > index) return ;
        if(tl == tr){
            t[node] = val ;
        }
        else{
            int mid = tl + ((tr-tl)>>1) ;
            int lft = (node << 1) ;
            int rght = lft + 1;
 
            update(lft,index,tl,mid,val) ;
            update(rght,index,mid+1,tr,val) ;
            t[node] = min(t[lft],t[rght]) ;
        }
 
    }
 
    ll query(int node , int l , int r , int tl , int tr){
 
        if(tl > r || tr < l) return INF ;
        if(tl >= l && tr <= r){
            return t[node];
        }
        else{
            int mid = tl + ((tr-tl)>>1) ;
            int lft = (node << 1) ;
            int rght = lft + 1;
 
            ll q1 = query(lft,l,r,tl,mid) ;
            ll q2 = query(rght,l,r,mid+1,tr) ;
 
            return min(q1,q2) ;
        }
    }
 
    void build(vi &v, int node , int tl , int tr){
        if(tl == tr){
            t[node] = v[tl];
        }
        else{
            int mid = tl + ((tr - tl) >> 1);
            int lft = (node << 1);
            int rght = lft + 1;
 
            build(v,lft,tl,mid);
            build(v,rght,mid+1,tr);
            t[node] = min(t[lft] ,t[rght]);
        }
    }
};


void solve() {
    int n, q; 
    cin >> n >> q; 

    vi v = {5, 2, 6, 3, 7};

    // Declaración con n de espacio 
    Segment_tree seg(n);

    // Inicialización, el nodo raíz siempre con índice 1, y los límites del árbol de 0 a n-1
    seg.build(v, 1, 0, n-1); 

    while(q--){
        int t;
        cin >> t; 

        // Actualización
        if(t == 1){
            int k, u; 
            cin >> k >> u; 
            seg.update(1, k-1, 0, n-1, u); 
        }

        // Query
        else{
            int a, b; 
            cin >> a >> b; 
            cout << seg.query(1, a-1, b-1, 0, n-1) << "\n"; 
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