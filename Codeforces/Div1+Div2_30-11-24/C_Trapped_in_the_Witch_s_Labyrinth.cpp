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

vi a = {1, -1, 0, 0};
vi b = {0, 0, 1, -1};

bool noEsCasillaDeUno(vector<vector<char>> &lab, int i, int j)
{

    bool uno = false;

    for (int k = 0; k < 4; k++)
    {
        if (lab[i + a[k]][j + b[k]] == '?')
            uno = true;
    }

    return uno;
}

void bfs(vector<vector<char>> &lab, vector<vector<bool>> &escape, int i, int j)
{
    queue<ii> cola;
    cola.push({i, j});

    lab[i][j] = 'x';
    escape[i][j] = false;

    while (!cola.empty())
    {
        auto u = cola.front();
        cola.pop();

        for (int k = 0; k < 4; k++)
        {
            if (lab[u.f + a[i]][u.s + b[i]] == '?')
            {
                lab[u.f + a[i]][u.s + b[i]] = 'x';
                escape[u.f + a[i]][u.s + b[i]] = false;
                cola.push({u.f + a[i], u.s + b[i]});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> lab(n + 2, vector<char>(m + 2, 'x'));
    vector<vector<bool>> escape(n + 2, vector<bool>(m + 2, false));

    int numEscape = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> lab[i][j];

    for (int j = 1; j <= m; j++)
    {
        if (lab[1][j] == 'U')
            escape[1][j] = true;

        if (lab[m][j] == 'D')
            escape[m][j] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (lab[i][1] == 'L')
            escape[i][1] = true;

        if (lab[i][m] == 'R')
            escape[i][m] = true;
    }

    if (lab[1][1] == 'U')
    {
        for (int i = 1; i <= n; i++)
        {
            if (lab[i][1] == 'U')
            {
                escape[i][1] = true;
            }
            else
            {
                break;
            }
        }
    }

    if (lab[1][1] == 'L')
    {
        for (int i = 1; i <= n; i++)
        {
            if (lab[1][i] == 'L')
            {
                escape[1][i] = true;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (lab[i][j] == '?' && noEsCasillaDeUno(lab, i, j))
            {
                bfs(lab, escape, i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {
            cout << lab[i][j];
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
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}