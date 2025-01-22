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
const ll INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vll> mat(n + 2, vll(m + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vll sum_filas(n);
    vll sum_colum(m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum_filas[i] += mat[i][j];
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            sum_colum[j] += mat[i][j];
        }
    }

    ll l = -1e15;
    ll r = 1e15;

    while (l <= r)
    {
    }
}

int main()
{
    owo

        int tt = 1;
    cin >> tt;

    while (tt--)
    {
        solve();
    }

    return 0;
}