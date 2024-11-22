#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
typedef pair<int, int> ii;
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

vi a = {0, 0, -1, 1};
vi b = {1, -1, 0, 0};

int bfs(ii inicio, vector<vi> &grid, vector<vector<bool>> &vis)
{

    int res = 0;
    queue<ii> cola;
    cola.push(inicio);
    vis[inicio.f][inicio.s] = true;

    while (!cola.empty())
    {
        ii u = cola.front();
        cola.pop();

        res += grid[u.f][u.s];

        for (int i = 0; i < 4; i++)
        {
            if (!vis[u.f + a[i]][u.s + b[i]] && grid[u.f + a[i]][u.s + b[i]] != 0)
            {
                vis[u.f + a[i]][u.s + b[i]] = true;
                cola.push({u.f + a[i], u.s + b[i]});
            }
        }
    }

    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> grid(n + 2, vi(m + 2, 0));
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] != 0 && !vis[i][j])
            {
                res = max(res, bfs({i, j}, grid, vis));
            }
        }
    }

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}