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

int n, d;

double redondear(double num)
{
    return round(num * 100.0) / 100.0;
}

pii good(double media, vi &nums)
{
    vector<double> prefix_min(sz(nums) + 1);
    vector<double> prefix(sz(nums) + 1, 0.0);
    vi indices(sz(nums) + 1);
    prefix[0] = -media;
    prefix_min[0] = prefix[0];
    for (int i = 1; i <= sz(nums); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i] - media;

        if (prefix_min[i - 1] < prefix[i])
        {
            prefix_min[i] = prefix_min[i - 1];
            indices[i] = indices[i - 1];
        }
        else
        {
            prefix_min[i] = prefix[i];
            indices[i] = i;
        }
    }

    for (int r = d; r <= sz(nums); r++)
    {
        if (prefix_min[r - d] <= prefix[r])
        {
            return {indices[r - d] + 1, r};
        }
    }

    return {-1, -1};
}

void solve()
{
    cin >> n >> d;

    vi nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    double l = -1;
    double r = 101.0;

    pii res = {-1, -1};

    for (int i = 0; i < 100; i++)
    {
        double m = l + (r - l) / 2;

        auto it = good(m, nums);
        if (it.fi != -1)
        {
            res = it;
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << res.fi << " " << res.se;
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