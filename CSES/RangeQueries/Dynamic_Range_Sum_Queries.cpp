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

vll nums;
vll st;

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v] = nums[tl];
        return;
    }
    int tm = tl + (tr - tl) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int v, int tl, int tr, int pos, ll val)
{
    if (tl == tr)
    {
        st[v] = val;
        return;
    }
    int tm = tl + (tr - tl) / 2;

    if (pos <= tm)
    {
        update(v * 2, tl, tm, pos, val);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    st[v] = st[v * 2] + st[v * 2 + 1];
}

ll query(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st[v];
    }
    if (tl > r || tr < l)
    {
        return 0;
    }
    int tm = tl + (tr - tl) / 2;
    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    nums.assign(n, 0);
    st.assign(n * 4, 0);

    read_vll(nums, n);

    build(1, 0, n - 1);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int k;
            ll u;
            cin >> k >> u;
            update(1, 0, n - 1, k - 1, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
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