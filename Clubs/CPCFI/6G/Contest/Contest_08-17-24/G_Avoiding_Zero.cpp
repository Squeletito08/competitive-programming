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

    vi pos;
    vi neg;

    int sum_pos = 0;
    int sum_neg = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            neg.pb(x);
            sum_neg += x;
        }
        else
        {
            pos.pb(x);
            sum_pos += x;
        }
    }

    vi res;

    if (sum_neg + sum_pos == 0)
    {
        cout << "NO" << endl;
        return;
    }

    if (sum_pos > -sum_neg)
    {
        sort(rall(pos));
        for (auto x : pos)
        {
            res.pb(x);
        }
        for (auto x : neg)
        {
            res.pb(x);
        }
    }
    else
    {
        for (auto x : neg)
        {
            res.pb(x);
        }
        for (auto x : pos)
        {
            res.pb(x);
        }
    }

    cout << "YES" << endl;
    for (auto x : res)
    {
        cout << x << " ";
    }

    cout << endl;
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