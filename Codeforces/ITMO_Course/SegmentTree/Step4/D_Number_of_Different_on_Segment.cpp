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

struct nodo
{
    bitset<41> elems;

    nodo() {};

    nodo(int num)
    {
        elems[num] = true;
    }

    nodo(const nodo &a, const nodo &b)
    {
        elems = a.elems | b.elems;
    }

    void update(int ant, int act)
    {
        elems[ant] = 0;
        elems[act] = 1;
    }
};

vector<nodo> st;

void build(int v, int tl, int tr, vi &nums)
{
    if (tl == tr)
    {
        st[v] = nodo(nums[tl]);
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, nums);
    build(v * 2 + 1, tm + 1, tr, nums);

    st[v] = nodo(st[v * 2], st[v * 2 + 1]);
}

nodo query(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st[v];
    }

    if (tl > r || tr < l)
    {
        return nodo();
    }

    int tm = (tl + tr) / 2;

    return nodo(query(v * 2, tl, tm, l, r), query(v * 2 + 1, tm + 1, tr, l, r));
}

void update(int v, int tl, int tr, int i, int ant, int act)
{
    if (tl == tr)
    {
        st[v].update(ant, act);
        return;
    }

    int tm = (tr + tl) / 2;

    if (i <= tm)
    {
        update(v * 2, tl, tm, i, ant, act);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, i, ant, act);
    }

    st[v] = nodo(st[v * 2], st[v * 2 + 1]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vi nums(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    st.assign(4 * n, nodo());

    build(1, 1, n, nums);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x, y;
            cin >> x >> y;

            nodo res = query(1, 1, n, x, y);
            cout << res.elems.count() << endl;
        }

        else
        {
            int i, val;
            cin >> i >> val;
            update(1, 1, n, i, nums[i], val);
            nums[i] = val;
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