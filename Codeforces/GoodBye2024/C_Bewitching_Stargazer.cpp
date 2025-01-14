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

ll divisiones(ll l, ll r, ll k)
{

    if (r - l + 1 < k)
    {
        return 0;
    }

    ll m = l + (r - l) / 2;

    cout << "Suma -> " << m << endl;
    if ((r - l + 1) % 2 == 0)
    {
        return divisiones(l, m, k) + divisiones(m + 1, r, k);
    }

    return m + divisiones(l, m - 1, k) + divisiones(m + 1, r, k);
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    divisiones(1, n, k);

    ll aux = n;
    while (n > k && n > 1)
    {
        n = (n + 1) / 2;
    }

    ll res = 0;

    for (int i = n; i < aux; i += n)
    {
        res += i;
    }

    cout << res << endl;
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