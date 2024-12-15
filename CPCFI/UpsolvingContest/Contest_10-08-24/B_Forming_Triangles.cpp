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
    ll n;
    cin >> n;
    vll nums(n);
    read_vll(nums, n);
    sort(all(nums));

    ll res = 0;

    for (int i = n - 1; i >= 2; i--)
    {
        ll sum = nums[i] + nums[i - 1];
        auto it = lower_bound(nums.begin() + i + 1, nums.end(), sum);

        cout << "suma -> " << sum << endl;
        cout << "it -> " << it - nums.begin() << endl;
        cout << "res -> " << res << endl;

        if (it == nums.end())
        {
            ll num = n - i;
            res += (num * (num - 1)) / 2;
        }
        else
        {
            ll num = it - nums.begin() - i - 1;
            res += (num * (num - 1)) / 2;
        }
    }
    cout << res << endl
         << endl
         << endl;
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