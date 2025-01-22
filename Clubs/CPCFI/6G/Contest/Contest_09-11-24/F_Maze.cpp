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

vi a = {0, 0, 1, -1};
vi b = {1, -1, 0, 0};

vector<vector<char>> maze;
vector<vector<bool>> vis;

void bfs(ii inicio, int x)
{
    queue<ii> cola;
    cola.push(inicio);
    vis[inicio.f][inicio.s] = true;
    x--;

    while (!cola.empty() && x)
    {
        auto u = cola.front();
        cola.pop();

        for (int i = 0; i < 4 && x; i++)
        {
            if (!vis[u.f + a[i]][u.s + b[i]] && maze[u.f + a[i]][u.s + b[i]] == '.')
            {
                vis[u.f + a[i]][u.s + b[i]] = true;
                x--;
                cola.push({u.f + a[i], u.s + b[i]});
            }
        }
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    maze.resize(n + 2, vector<char>(m + 2, '#'));
    vis.resize(n + 2, vector<bool>(m + 2, false));

    ii inicio;
    int ctd = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
            {
                inicio = {i, j};
                ctd++;
            }
            maze[i][j] = x;
        }
    }

    bfs(inicio, ctd - k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maze[i][j] == '.' && !vis[i][j])
            {
                cout << "X";
            }
            else
            {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}