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

const int MAX = 3 * 1e5 + 2;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vi nums(m);
    read_vi(nums, m);

    set<int> cuales_se;

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        cuales_se.insert(x);
    }

    set<int> cuales_no_se;

    for (int i = 1; i <= n; i++)
    {
        if (!cuales_se.count(i))
        {
            cuales_no_se.insert(i);
        }
    }

    if (cuales_no_se.size() > 1)
    {
        string res = "";
        for (int i = 0; i < m; i++)
        {
            res += "0";
        }

        cout << res << endl;
        return;
    }

    if (cuales_no_se.size() == 0)
    {
        string res = "";
        for (int i = 0; i < m; i++)
        {
            res += "1";
        }

        cout << res << endl;
        return;
    }

    string res = "";

    for (int i = 0; i < m; i++)
    {
        if (cuales_no_se.count(nums[i]))
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