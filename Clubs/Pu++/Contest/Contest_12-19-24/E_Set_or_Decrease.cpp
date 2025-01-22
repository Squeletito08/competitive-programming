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

ll num_pasos(ll sum, vll &nums, ll x, ll k, int n)
{
    ll pasos = abs(nums[n - 1] - x);

    sum -= x;

    int i = 0;
    while (sum > k && i < n - 1)
    {
        sum -= nums[i];
        sum += x;
        i++;
        pasos++;
    }

    return pasos;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll nums(n);
    read_vll(nums, n);

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if (sum <= k)
    {
        cout << 0 << endl;
        return;
    }

    sort(all(nums), greater<int>());

    ll min = nums[n - 1];

    ll dif = sum - k;

    ll res = dif;

    ll l = 1, r = dif;

    while (l <= r)
    {

        ll m = l + (r - l) / 2;
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