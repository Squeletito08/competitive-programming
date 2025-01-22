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

bool valido(vi &nums, double x, int k)
{
    int num = 0;

    for (int i = 0; i < sz(nums); i++)
    {
        num += nums[i] / x;
    }

    return num >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi nums(n);
    read_vi(nums, n);

    double l = 0;
    double r = 1e7;

    double res = 0;

    for (int i = 0; i < 100; i++)
    {
        double m = l + (r - l) / 2;

        if (valido(nums, m, k))
        {
            res = m;
            l = m;
        }
        else
        {
            r = m;
        }
    }

    cout << setprecision(10) << res << endl;
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