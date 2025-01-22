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

ll n, k;

bool good(ll m, vi &nums)
{
    ll ctd = 1;

    ll i = 0;

    while (i < n - 1)
    {
        auto it = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + m);

        if (it == nums.end())
        {
            break;
        }

        i = distance(nums.begin(), it);
        ctd++;
    }

    return ctd >= k;
}

void solve()
{
    cin >> n >> k;

    vi nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ll l = 0;
    ll r = 1e9;

    ll res = 0;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        if (good(m, nums))
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << res << endl;
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
