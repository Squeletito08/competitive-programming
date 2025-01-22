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

    vi st;

    ST(vi &a)
    {
        st.assign(sz(a) * 4, 0);
        build(1, 0, sz(a) - 1, a);
    }

    void build(int v, int tl, int tr, vi &a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
        {
            st[v] -= val;
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

        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }

    int query(int v, int tl, int tr, int val)
    {
        if (tl == tr)
        {
            return tl;
        }

        int tm = tl + (tr - tl) / 2;

        return (st[v * 2] >= val) ? query(v * 2, tl, tm, val) : query(v * 2 + 1, tm + 1, tr, val);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vi hoteles(n);
    read_vi(hoteles, n);

    ST st{hoteles};
    while (m--)
    {
        int x;
        cin >> x;

        if (st.st[1] < x)
        {
            cout << 0 << " ";
            continue;
        }

        int i = st.query(1, 0, n - 1, x);
        cout << i + 1 << " ";
        st.update(1, 0, n - 1, i, x);
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