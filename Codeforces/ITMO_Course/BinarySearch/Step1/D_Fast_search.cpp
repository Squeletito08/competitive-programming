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
const int INF = INT_MAX;

int bin_s(vi &nums, int x)
{
    int res = -1;
    int l = 0;
    int r = sz(nums) - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] <= x)
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    vi nums(n);
    read_vi(nums, n);
    nums.pb(INF);
    nums.pb(-INF);

    sort(all(nums));

    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;

        int i = lower_bound(all(nums), l) - nums.begin();
        int j = bin_s(nums, r);

        if (j < i)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << j - i + 1 << " ";
        }
    }
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