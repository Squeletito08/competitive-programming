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

    vi nums(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }

    vll prefix(n + 1);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    while (q--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        int sum = 0;

        sum += prefix[a - 1] - prefix[0];

        sum += prefix[n] - prefix[b];

        sum += (b - a + 1) * k;

        if (sum % 2 != 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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