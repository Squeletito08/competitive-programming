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

ll n, m;

ll numberOfBallons(ll time, ll t, ll z, ll y)
{
    ll timeRequired = z * t + y;
    return ((time / timeRequired) * z) + min((time % timeRequired) / t, z);
}

bool isPoss(ll time, vector<tuple<ll, ll, ll>> &workers)
{
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        const auto [t, z, y] = workers[i];
        total += numberOfBallons(time, t, z, y);
    }

    return total >= m;
}

void solve()
{
    cin >> m >> n;

    vector<tuple<ll, ll, ll>> workers;

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        workers.pb({a, b, c});
    }

    ll l = 0;
    ll r = 1e9;

    ll finalTime = -1;

    while (l <= r)
    {
        ll time = l + (r - l) / 2;

        if (isPoss(time, workers))
        {
            finalTime = time;
            r = time - 1;
        }
        else
        {
            l = time + 1;
        }
    }

    cout << finalTime << endl;

    for (int i = 0; i < n; i++)
    {
        const auto [t, z, y] = workers[i];
        ll x = numberOfBallons(finalTime, t, z, y);

        cout << min(m, x) << " ";
        m = max(0ll, m - x);
    }
    cout << endl;
}

int main()
{
    owo

        ll tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}