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
    int n;
    cin >> n;

    vector<pii> pares;

    vll nums(2 * n + 1, 0);
    map<int, int> dist;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pares.pb({a, b});

        if (a == b)
        {
            nums[a] = 1;
            dist[a]++;
        }
    }

    vll prefix(2 * n + 2, 0);

    for (int i = 1; i <= sz(nums); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    string res = "";

    for (int i = 0; i < n; i++)
    {
        int a = pares[i].fi;
        int b = pares[i].se;

        if (a == b)
        {
            if (dist[a] > 1)
            {
                res += "0";
            }
            else
            {
                res += "1";
            }
            continue;
        }

        ll sum = prefix[b] - prefix[a - 1];
        ll cantidad = b - a + 1;
        if (cantidad - sum >= 1)
        {
            res += "1";
        }
        else
        {
            res += "0";
        }
    }

    cout << res << endl;
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