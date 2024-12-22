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

ll ask(int l, int r)
{
    cout << "? " << (r - l + 1) << " ";
    for (int i = l; i <= r; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    ll x;
    cin >> x;
    return x;
}

void ans(int x)
{
    cout << "! " << x << endl;
}

void solve()
{
    int n;
    cin >> n;
    vi nums(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    vll prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    int l = 1, r = n;

    while (l < r)
    {
        int m = (l + r) / 2;
        ll izq = prefix[m] - prefix[l - 1];
        ll der = prefix[r] - prefix[m];

        ll x = ask(l, m);

        if (izq != x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    ans(l);
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