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

vector<pll> st;

pll merge(pll a, pll b)
{
    return {a.fi + b.fi, a.se + b.se};
}

void build(int v, int tl, int tr, vi &nums)
{
    if (tl == tr)
    {
        if (tl % 2 != 0)
        {
            st[v] = {nums[tl], 0};
        }
        else
        {
            st[v] = {0, nums[tl]};
        }
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, nums);
    build(v * 2 + 1, tm + 1, tr, nums);

    st[v] = merge(st[v * 2], st[v * 2 + 1]);
}

void update(int v, int tl, int tr, int i, int val)
{
    if (tl == tr)
    {
        if (tl % 2 != 0)
        {
            st[v] = {val, 0};
        }
        else
        {
            st[v] = {0, val};
        }
        return;
    }

    int tm = (tl + tr) / 2;
    if (i <= tm)
    {
        update(v * 2, tl, tm, i, val);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, i, val);
    }

    st[v] = merge(st[v * 2], st[v * 2 + 1]);
}

pll query(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st[v];
    }
    if (tl > r || tr < l)
    {
        return {0, 0};
    }

    int tm = (tl + tr) / 2;

    return merge(query(v * 2, tl, tm, l, r), query(v * 2 + 1, tm + 1, tr, l, r));
}

void solve()
{
    int n;
    cin >> n;

    vi nums(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    st.assign(4 * n, {0, 0});

    build(1, 1, n, nums);

    int m;
    cin >> m;

    while (m--)
    {
        int op;
        cin >> op;

        if (op == 0)
        {
            int i, j;
            cin >> i >> j;
            update(1, 1, n, i, j);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            pll res = query(1, 1, n, l, r);

            if (l % 2 != 0)
            {
                cout << res.fi - res.se << endl;
            }
            else
            {
                cout << res.se - res.fi << endl;
            }
        }
    }
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