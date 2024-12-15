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

struct ST
{
    vector<pll> st;

    ST(vll &a)
    {
        st.assign(sz(a) * 4, {0, 0});
        build(1, 0, sz(a) - 1, a);
    }

    pll merge(pll a, pll b)
    {
        if (a.fi == b.fi)
        {
            return {a.fi, a.se + b.se};
        }
        return min(a, b);
    }

    void build(int v, int l, int r, vll &a)
    {
        if (l == r)
        {
            st[v] = {a[l], 1};
            return;
        }
        int m = l + (r - l) / 2;
        build(v * 2, l, m, a);
        build(v * 2 + 1, m + 1, r, a);

        st[v] = merge(st[v * 2], st[v * 2 + 1]);
    }

    void update(int v, int tl, int tr, int i, ll val)
    {
        if (tl == tr)
        {
            st[v] = {val, 1};
            return;
        }
        int m = tl + (tr - tl) / 2;
        if (i <= m)
        {
            update(v * 2, tl, m, i, val);
        }
        else
        {
            update(v * 2 + 1, m + 1, tr, i, val);
        }

        st[v] = merge(st[v * 2], st[v * 2 + 1]);
    }

    pll query(int v, int tl, int tr, int i, int j)
    {
        if (tr < i || tl > j)
        {
            return {INF, 0};
        }
        if (tl >= i && tr <= j)
        {
            return st[v];
        }
        int m = tl + (tr - tl) / 2;

        auto izq = query(v * 2, tl, m, i, j);
        auto der = query(v * 2 + 1, m + 1, tr, i, j);

        return merge(izq, der);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vll v(n);
    read_vll(v, n);

    ST st{v};

    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i;
            cin >> i;
            ll v;
            cin >> v;
            st.update(1, 0, n - 1, i, v);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            auto res = st.query(1, 0, n - 1, i, j - 1);
            cout << res.fi << " " << res.se << endl;
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