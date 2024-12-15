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

vi st;
unordered_map<char, int> letras;

void build(int v, int tl, int tr, string &s)
{
    if (tl == tr)
    {
        char c = s[tl];
        int pos = letras[c];
        st[v] |= (1 << pos);
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, s);
    build(v * 2 + 1, tm + 1, tr, s);
    st[v] = st[v * 2] | st[v * 2 + 1];
}

void update(int v, int tl, int tr, int pos, char ant, char act)
{
    if (tr == tl)
    {
        int c_ant = letras[ant];
        int c_act = letras[act];

        st[v] &= ~(1 << c_ant);
        st[v] |= (1 << c_act);

        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm)
    {
        update(v * 2, tl, tm, pos, ant, act);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, pos, ant, act);
    }

    st[v] = st[v * 2] | st[v * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st[v];
    }
    if (tl > r || tr < l)
    {
        return 0;
    }

    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, r) | query(v * 2 + 1, tm + 1, tr, l, r);
}

void solve()
{

    string s;
    cin >> s;
    int q;
    cin >> q;

    int x = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        letras[c] = x;
        x++;
    }

    int n = sz(s);
    st.assign(4 * n, 0);
    build(1, 0, n - 1, s);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int pos;
            cin >> pos;
            char c;
            cin >> c;
            char ant = s[pos - 1];

            update(1, 0, n - 1, pos - 1, ant, c);
            s[pos - 1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int res = query(1, 0, n - 1, l - 1, r - 1);
            cout << __builtin_popcount(res) << endl;
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