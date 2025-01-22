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

const ll MAX = 1e5 + 10;

ll st[MAX * 4], lazy[MAX * 4];

void clear(int v, ll l, ll r)
{
    if (l == r)
    {
        st[v] = 0;
        lazy[v] = 0;
    }
    else
    {
        ll m = (l + r) / 2;
        clear(v * 2, l, m);
        clear(v * 2 + 1, m + 1, r);
        st[v] = lazy[v] = 0;
    }
}

void push(int v, ll l, ll r)
{
    ll m = (l + r) / 2;
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    st[v * 2] += (m - l + 1) * lazy[v];
    st[v * 2 + 1] += (r - m) * lazy[v];
    lazy[v] = 0;
}

ll query(int v, ll tl, ll tr, ll l, ll r)
{
    if (l <= tl && tr <= r)
        return st[v];
    if (tl > r || tr < l)
        return 0;
    ll tm = (tl + tr) / 2;
    push(v, tl, tr);
    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

ll queryIndice(int v, ll tl, ll tr, ll i)
{
    if (tl == tr)
    {
        return st[v];
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    if (i <= tm)
    {
        return queryIndice(v * 2, tl, tm, i);
    }

    return queryIndice(v * 2 + 1, tm + 1, tr, i);
}

void update(int v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l <= tl && tr <= r)
    {
        st[v] += val * (tr - tl + 1);
        lazy[v] += val;
        return;
    }
    if (tl > r || tr < l)
        return;
    ll tm = (tl + tr) / 2;
    push(v, tl, tr);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    st[v] = st[v * 2] + st[v * 2 + 1];
}

void printST(int n)
{

    cout << "st: " << endl;
    for (int i = 0; i < 4 * n; i++)
    {
        cout << "st: " << i << " -> " << st[i] << endl;
        cout << "lz: " << i << " -> " << lazy[i] << endl;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    clear(1, 0, n - 1);

    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r - 1, v);
        }
        else
        {
            ll i;
            cin >> i;
            cout << queryIndice(1, 0, n - 1, i) << endl;
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
