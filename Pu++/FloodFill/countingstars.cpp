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

void bfs(ii inicio, vector<vector<char>> &grid)
{
    queue<ii> cola;
    cola.push(inicio);
    grid[inicio.f][inicio.s] = '#';

    while (!cola.empty())
    {
        auto u = cola.front();
        cola.pop();

        for (int i = 0; i < 4; i++)
        {
            if (grid[u.f + a[i]][u.s + b[i]] != '#')
            {
                grid[u.f + a[i]][u.s + b[i]] = '#';
                cola.push({u.f + a[i], u.s + b[i]});
            }
        }
    }
}

int solve(int n, int m)
{
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ctd = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] != '#')
            {
                ctd++;
                bfs({i, j}, grid);
            }
        }
    }

    return ctd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    int n, m;

    while (cin)
    {
        cin >> n >> m;

        if (!cin)
        {
            break;
        }
        int res = 0;
        res = solve(n, m);
        cout << "Case " << t << ": " << res << endl;
        t++;
    }

    return 0;
}