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

bool cabe(ll x, ll y, ll seg, ll n)
{
    ll copias = 0;

    seg -= min(x, y);
    copias++;

    if (seg < 0)
    {
        return false;
    }

    copias += seg / x;
    copias += seg / y;

    return copias >= n;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll res = -1;

    ll l = 1;
    ll r = n * 20;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        if (cabe(x, y, m, n))
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << res << endl;
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