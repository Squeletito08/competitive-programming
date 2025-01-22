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
    int n, q;
    cin >> n >> q;

    vi nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vll pos(n + 10, 0);

    while (q--)
    {
        int i, j;
        cin >> i >> j;
        pos[i] += 1;
        pos[j + 1] += -1;
    }

    vll prefix(n + 10, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + pos[i];
    }

    sort(all(nums), greater<int>());

    sort(all(prefix), greater<int>());

    ll res = 0;

    for (int i = 0; i <= n; i++)
    {
        res += nums[i] * prefix[i];
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