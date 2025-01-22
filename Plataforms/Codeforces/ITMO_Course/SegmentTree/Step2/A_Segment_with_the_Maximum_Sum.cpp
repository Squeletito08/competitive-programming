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
    ll suma, seg, pref, suf;
};

vector<nodo> st;

nodo merge(nodo a, nodo b)
{

    nodo c;
    c.suma = a.suma + b.suma;
    c.seg = max(a.seg, max(b.seg, a.suf + b.pref));
    c.pref = max(a.pref, a.suma + b.pref);
    c.suf = max(b.suf, b.suma + a.suf);

    return c;
}

void build(int v, int tl, int tr, vll &nums)
{
    if (tl == tr)
    {
        if (nums[tl] > 0)
        {
            st[v].suma = st[v].seg = st[v].pref = st[v].suf = nums[tl];
        }
        else
        {
            st[v].seg = st[v].pref = st[v].suf = 0;
            st[v].suma = nums[tl];
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

        if (val > 0)
        {
            st[v].suma = st[v].seg = st[v].pref = st[v].suf = val;
        }
        else
        {
            st[v].seg = st[v].pref = st[v].suf = 0;
            st[v].suma = val;
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

void solve()
{
    int n, m;
    cin >> n >> m;

    st.assign(n * 4, {0, 0, 0, 0});

    vll nums(n);
    read_vll(nums, n);

    build(1, 0, n - 1, nums);

    // for (int i = 0; i < 4 * n; i++)
    // {
    //     cout << i << " -> " << endl;
    //     cout << "sum: " << st[i].suma << endl;
    //     cout << "seg: " << st[i].seg << endl;
    //     cout << "pref: " << st[i].pref << endl;
    //     cout << "suf: " << st[i].suf << endl
    //          << endl;
    // }

    cout << st[1].seg << endl;

    while (m--)
    {
        int i, v;
        cin >> i >> v;
        update(1, 0, n - 1, i, v);
        cout << st[1].seg << endl;
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