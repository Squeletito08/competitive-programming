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

long long binpow(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll minimo_bs(ll l1, ll r1, ll l2, ll r2, ll k_temp)
{
    ll res = -1;

    while (l1 <= r1)
    {
        ll m = l1 + (r1 - l1) / 2;

        ll num = m * k_temp;

        if (num >= l2 && num <= r2)
        {
            res = m;
            r1 = m - 1;
        }
        if (num < l2)
        {
            l1 = m + 1;
        }
        else if (num > r2)
        {
            r1 = m - 1;
        }
    }

    return res;
}

ll maximo_bs(ll l1, ll r1, ll l2, ll r2, ll k_temp)
{
    ll res = -1;

    while (l1 <= r1)
    {
        ll m = l1 + (r1 - l1) / 2;

        ll num = m * k_temp;

        if (num >= l2 && num <= r2)
        {
            res = m;
            l1 = m + 1;
        }
        if (num < l2)
        {
            l1 = m + 1;
        }
        else if (num > r2)
        {
            r1 = m - 1;
        }
    }

    return res;
}

void solve()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    ll res = 0;
    ll n = 0;
    ll k_temp = 1;
    while (l1 * k_temp <= r2)
    {
        ll a = minimo_bs(l1, r1, l2, r2, k_temp);

        if (a == -1)
        {
            n++;
            k_temp = binpow(k, n);
            continue;
        }

        ll b = maximo_bs(l1, r1, l2, r2, k_temp);

        res += b - a + 1;
        n++;
        k_temp = binpow(k, n);
    }

    cout << res << endl;
}

void solve2()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    ll res = 0;
    ll n = 0;
    ll k_temp = 1;

    ll a = (l2 % k_temp != 0 ? l2 / k_temp + 1 : l2 / k_temp);
    ll b = r2 / k_temp;

    while (b >= l1)
    {

        ll L = max(l1, a);
        ll R = min(r1, b);

        (L <= R) ? res += R - L + 1 : res += 0;

        n++;
        k_temp = binpow(k, n);
        a = (l2 % k_temp != 0 ? l2 / k_temp + 1 : l2 / k_temp);
        b = floor(r2 / k_temp);
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
        // solve();
        solve2();
    }

    return 0;
}