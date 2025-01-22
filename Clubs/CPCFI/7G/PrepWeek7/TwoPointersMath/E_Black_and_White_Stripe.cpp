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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ctd = 0;

    for (int i = 0; i < n; i++)
    {
        while (s[i] == 'B' && i < n)
        {
            ctd++;
            i++;

            if (ctd == k)
            {
                cout << 0 << endl;
                return;
            }
        }

        ctd = 0;
    }

    vi nums(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            nums[i] = 1;
        }
    }

    vll prefix(n + 1);

    prefix[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    ll m = INF;
    int anterior = 0;

    for (int i = 0; i <= n - k + 1; i++)
    {

        if (i != 0)
        {
            anterior = i - 1;
        }

        ll num_B = prefix[i + k - 1] - prefix[anterior];

        m = min(k - num_B, m);
    }

    cout << m << endl;
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