#include <bits/stdc++.h>
using namespace std;

#define owo                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void read_vi(vi &a, int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void read_vll(vll &a, int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
const ll MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<vector<pii>> graf;
vector<int> dist;
vector<int> padres;

int n, m, d;

void bfs(int inicio, int cota)
{
    queue<int> cola;
    cola.push(inicio);
    dist[inicio] = 0;
    padres[inicio] = inicio;

    while (!cola.empty())
    {
        int u = cola.front();
        cola.pop();

        for (auto &[v, w] : graf[u])
        {
            if (dist[v] == INF && w <= cota)
            {
                dist[v] = dist[u] + 1;
                padres[v] = u;
                cola.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> d;

    graf.resize(n + 1);
    dist.resize(n + 1, INF);
    padres.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].pb({b, c});
    }

    int l = 0;
    int r = 1e9;

    int res = 0;

    while (l <= r)
    {
        int cota = l + (r - l) / 2;

        if (good(cota))
        {
            res = cota;
            r = cota - 1;
        }
        else
        {
            l = cota + 1;
        }
    }

    good(res);

    if (dist[n] > d)
    {
        cout << -1 << endl;
        return;
    }

    cout << dist[n] << endl;

    vi camino;

    int inicio = n;

    while (inicio != 1)
    {
        camino.pb(inicio);
        inicio = padres[inicio];
    }

    camino.pb(1);
    reverse(all(camino));

    for (auto x : camino)
    {
        cout << x << " ";
    }
    cout << endl;
}

bool good(int cota)
{
    dist.assign(n + 1, INF);
    padres.assign(n + 1, -1);
    bfs(1, cota);

    return dist[n] <= d;
}

int main()
{
    owo

        int tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}