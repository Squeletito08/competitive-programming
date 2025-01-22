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

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    
    private:
    vi p, rank, setSize;
    int numSets;

    public:
    UnionFind(int N) {
        N++; 
        p.assign(N, 0); for (int i = 1; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N-1;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }
    
    int sizeOfSet(int i) { return setSize[findSet(i)]; } 

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

void solve(){
    int n, m; cin >> n >> m; 

    UnionFind uf(n); 

    int num_comp = n; 
    int l_max = 1; 

    while(m--){
        int a, b; 
        cin >> a >> b; 

        uf.unionSet(a, b); 
        l_max = max(max(uf.sizeOfSet(a), uf.sizeOfSet(b)), l_max);  

        cout << uf.numDisjointSets() << " " << l_max << endl; 
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