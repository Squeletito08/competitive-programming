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
    ll inv;
    ll freq[41];

    nodo() : inv(0)
    {
        memset(freq, 0, sizeof(freq));
    }
};

nodo neutro;
vector<nodo> st;

ll calculate(nodo &a, nodo &b)
{
    ll res = a.inv + b.inv;
    for (ll i = 2; i <= 40; i++)
    {
        for (ll j = 1; j <= i - 1; j++)
        {
            res += a.freq[i] * b.freq[j];
        }
    }

    return res;
}

void imprime_nodo(nodo &a)
{
    cerr << "inv -> " << a.inv << endl;

    cerr << "freq -> " << endl;
    for (ll i = 1; i <= 40; i++)
    {
        cerr << a.freq[i] << " ";
    }

    cerr << endl;
}

nodo merge(nodo &a, nodo &b)
{
    nodo c = nodo();

    for (ll i = 1; i <= 40; i++)
    {
        c.freq[i] = a.freq[i] + b.freq[i];
    }

    c.inv = calculate(a, b);

    return c;
}

void build(ll v, ll tl, ll tr, vll &nums)
{
    if (tl == tr)
    {
        st[v].inv = 0;
        st[v].freq[nums[tl]] = 1;
        return;
    }

    ll tm = (tl + tr) / 2;
    build(v * 2, tl, tm, nums);
    build(v * 2 + 1, tm + 1, tr, nums);

    st[v] = merge(st[v * 2], st[v * 2 + 1]);
}

nodo query(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl >= l && tr <= r)
    {
        return st[v];
    }

    if (tl > r || tr < l)
    {
        return neutro;
    }

    ll tm = (tl + tr) / 2;

    auto a = query(v * 2, tl, tm, l, r);
    auto b = query(v * 2 + 1, tm + 1, tr, l, r);

    return merge(a, b);
}

void update(ll v, ll tl, ll tr, ll i, ll val)
{
    if (tl == tr)
    {
        st[v] = nodo();
        st[v].freq[val] = 1;
        return;
    }

    ll tm = (tl + tr) / 2;

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
    ll n, q;
    cin >> n >> q;

    vll nums(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> nums[i];

    st.assign(4 * n, nodo());
    neutro = nodo();

    build(1, 1, n, nums);

    while (q--)
    {
        ll op;
        cin >> op;

        if (op == 1)
        {
            ll x, y;
            cin >> x >> y;

            nodo res = query(1, 1, n, x, y);
            cout << res.inv << endl;
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        }
    }
}

int main()
{
    owo

        ll tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}