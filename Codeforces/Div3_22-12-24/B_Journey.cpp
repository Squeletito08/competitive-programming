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

void solve()
{

    vi nums(3);
    ll n;
    cin >> n;

    cin >> nums[0];
    cin >> nums[1];
    cin >> nums[2];

    reverse(all(nums));

    ll sum = nums[0] + nums[1] + nums[2];

    ll div = (n / sum) + 1;

    sum = sum * div;

    ll res = div * 3;

    int i = 0;

    while (sum > n)
    {
        sum -= nums[i % 3];
        res--;
        i++;
    }

    if (sum == n)
    {
        cout << res << endl;
        return;
    }

    cout << res + 1 << endl;
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