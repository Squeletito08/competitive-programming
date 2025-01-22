#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, m;

bool valido(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

vector<ii> vecinos(int x, int i, int j) {
    vector<ii> vec;
    int bit;

    for (int k = 0; k < 4; k++) {
        bit = 1 << k;

        if (!(x & bit)) {
            switch (bit) {
                case 1:
                    if (valido(i, j - 1)) {
                        vec.pb({i, j - 1});
                    }
                    break;
                case 2:
                    if (valido(i - 1, j)) {
                        vec.pb({i - 1, j});
                    }
                    break;
                case 4:
                    if (valido(i, j + 1)) {
                        vec.pb({i, j + 1});
                    }
                    break;
                case 8:
                    if (valido(i + 1, j)) {
                        vec.pb({i + 1, j});
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return vec;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int bfs(ii inicio, ii objetivo, unordered_map<ii, vector<ii>, hash_pair>& g) {
    queue<ii> q;
    unordered_map<ii, int, hash_pair> dist;

    q.push(inicio);
    dist[inicio] = 0;

    while (!q.empty()) {
        ii actual = q.front();
        q.pop();

        if (actual == objetivo) {
            return dist[actual];  
        }

        for (auto vecino : g[actual]) {
            if (dist.find(vecino) == dist.end()) {
                dist[vecino] = dist[actual] + 1;
                q.push(vecino);
            }
        }
    }

    return -1;  
}

void solve() {
    while (true) {
        string s; 
        getline(cin, s);  

        if (s.empty()) break;  
        istringstream iss(s);
        iss >> n >> m;  

        int i, j;
        cin >> i >> j;  

        ii inicio = {i, j};

        vvi lab(n, vi(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> lab[i][j];
            }
        }

        unordered_map<ii, vector<ii>, hash_pair> g;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<ii> vec = vecinos(lab[i][j], i, j);
                for (auto x : vec) {
                    g[{i, j}].pb(x);
                }
            }
        }

        vector<ii> salidas;

        for (int j = 0; j < m; j++) {
            int bit = 2;
            if (!(lab[0][j] & bit)) {
                salidas.pb({0, j});
            }
        }

        for (int j = 0; j < m; j++) {
            int bit = 8;
            if (!(lab[n - 1][j] & bit)) {
                salidas.pb({n - 1, j});
            }
        }

        for (int i = 0; i < n; i++) {
            int bit = 1;
            if (!(lab[i][0] & bit)) {
                salidas.pb({i, 0});
            }
        }

        for (int i = 0; i < n; i++) {
            int bit = 4;
            if (!(lab[i][m - 1] & bit)) {
                salidas.pb({i, m - 1});
            }
        }

        int resultado = INT_MAX;
        for (auto salida : salidas) {
            int distSalida = bfs(inicio, salida, g);
            if (distSalida != -1) {
                resultado = min(resultado, distSalida);
            }
        }

        if (resultado == INT_MAX) {
            cout << -1 << "\n"; 
        } else {
            cout << resultado << "\n"; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
