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

bool caben(ll w, ll h, ll x, ll n)
{
    ll a = x / h;
    ll b = x / w;

    return a >= (n / (double)b);
}

ll bin_s(ll l, ll r, ll n, ll w, ll h)
{

    ll res = -1;

    while (l <= r)
    {

        ll m = l + (r - l) / 2;

        if (caben(w, h, m, n))
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return res;
}

void solve()
{
    ll w, h, n;
    cin >> w >> h >> n;

    cout << bin_s(1, max(w, h) * n, n, w, h) << endl;
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