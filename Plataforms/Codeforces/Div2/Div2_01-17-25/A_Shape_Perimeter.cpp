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

    vector<pii> puntos(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        puntos[i] = {a, b};
    }

    for (int i = 1; i < n; i++)
    {
        puntos[i] = {puntos[i - 1].fi + puntos[i].fi, puntos[i - 1].se + puntos[i].se};
    }

    vector<pii> finales(n);

    for (int i = 0; i < n; i++)
    {
        finales[i] = {puntos[i].fi + m, puntos[i].se + m};
    }

    ll peri = m * 4 * n;
    ll resta = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (finales[i].fi > puntos[i + 1].fi && finales[i].se > puntos[i + 1].se)
        {
            resta += finales[i].fi - puntos[i + 1].fi;
            resta += finales[i].se - puntos[i + 1].se;
        }
    }

    cout << peri - resta * 2 << endl;
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