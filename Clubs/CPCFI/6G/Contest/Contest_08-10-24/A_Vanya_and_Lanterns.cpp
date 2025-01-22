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

void solve()
{
    ll n, l;
    cin >> n >> l;

    vll nums(n);

    read_vll(nums, n);

    sort(all(nums));

    double res = 0;

    for (int i = 1; i < n; i++)
    {
        res = max(res, (double)(nums[i] - nums[i - 1]) / 2);
    }

    if (nums[0] != 0)
    {
        res = max(res, (double)nums[0]);
    }

    if (nums[n - 1] != l)
    {
        res = max(res, (double)(l - nums[n - 1]));
    }

    cout << fixed;
    cout.precision(10);
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}