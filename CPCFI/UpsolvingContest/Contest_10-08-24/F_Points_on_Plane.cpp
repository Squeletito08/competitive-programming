#include <bits/stdc++.h>
using namespace std;

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

ll bs(ll l, ll r, ll n)
{
    ll res = 0;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        if (m && m > n / m)
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
    ll n;
    cin >> n;

    ll res = (int)ceil((int)sqrt(n));

    cout << (n == res * res ? res - 1 : res) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt--)
    {
        solve();
    }

    return 0;
}