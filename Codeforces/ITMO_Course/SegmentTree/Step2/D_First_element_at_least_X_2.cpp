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

vll st;

void build(int v, int tl, int tr, vll &nums)
{
    if (tl == tr)
    {
        st[v] = nums[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, nums);
    build(v * 2 + 1, tm + 1, tr, nums);

    st[v] = max(st[v * 2], st[v * 2 + 1]);
}

void update(int v, int tl, int tr, int i, int val)
{
    if (tl == tr)
    {
        st[v] = val;
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

    st[v] = max(st[v * 2], st[v * 2 + 1]);
}

int query(int v, int tl, int tr, int val, int l)
{
    if (tl == tr)
    {
        return tl;
    }

    int tm = (tl + tr) / 2;

    if (st[v * 2] >= val && l >= 0 && l <= tm)
    {
        return query(v * 2, tl, tm, val, l);
    }

    else if (st[v * 2 + 1] >= val && tm + 1 <= l && l < tr)
    {
        return query(v * 2 + 1, tm + 1, tr, val, l);
    }

    return -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vll nums(n);
    read_vll(nums, n);
    st.assign(4 * n, -INF);

    build(1, 0, n - 1, nums);

    while (m--)
    {
        int p;
        cin >> p;

        if (p == 1)
        {
            int i, v;
            cin >> i >> v;
            update(1, 0, n - 1, i, v);
        }
        else
        {

            int x, l;
            cin >> x >> l;
            cout << query(1, 0, n - 1, x, l) << endl;
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