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

bool good(ll m, vll &nums, int k)
{

    int n = sz(nums);
    int numSegmentos = 0;

    int i = 0;

    ll suma = 0;

    while (i < n && suma <= m)
    {
        if (suma + nums[i] <= m)
        {
            suma += nums[i];
        }
        else
        {
            suma = nums[i];
            numSegmentos++;
        }

        if (suma > m)
        {
            return false;
        }
        i++;
    }

    if (suma <= m)
    {
        numSegmentos++;
    }
    else
    {
        return false;
    }

    return numSegmentos <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vll nums(n);

    ll suma = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        suma += x;
        nums[i] = x;
    }

    ll l = 0;
    ll r = suma;

    ll res = 0;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        if (good(m, nums, k))
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