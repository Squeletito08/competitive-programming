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

    st[v] = st[v * 2] + st[v * 2 + 1];
}

void update(int v, int tl, int tr, int i)
{
    if (tl == tr)
    {
        st[v] = !st[v];
        return;
    }

    int tm = (tl + tr) / 2;

    if (i <= tm)
    {
        update(v * 2, tl, tm, i);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, i);
    }

    st[v] = st[v * 2] + st[v * 2 + 1];
}

int query(int v, int tl, int tr, int val)
{
    if (tl == tr)
    {
        return tl;
    }

    int tm = (tl + tr) / 2;

    if (st[v * 2] >= val)
    {
        return query(v * 2, tl, tm, val);
    }

    return query(v * 2 + 1, tm + 1, tr, val - st[v * 2]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vll nums(n);
    st.assign(4 * n, 0);

    read_vll(nums, n);

    build(1, 0, n - 1, nums);

    while (m--)
    {
        int p, v;
        cin >> p >> v;

        if (p == 1)
        {
            update(1, 0, n - 1, v);
        }
        else
        {
            cout << query(1, 0, n - 1, v + 1) << endl;
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