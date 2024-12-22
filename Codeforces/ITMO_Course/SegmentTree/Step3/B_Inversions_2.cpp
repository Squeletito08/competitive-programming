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

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v] = 1;
        return;
    }

    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    st[v] = st[v * 2] + st[v * 2 + 1];
}

int query(int v, int tl, int tr, int val)
{
    if (tl == tr)
    {
        return tl;
    }

    int tm = (tl + tr) / 2;

    if (st[v * 2 + 1] >= val)
    {
        return query(v * 2 + 1, tm + 1, tr, val);
    }

    return query(v * 2, tl, tm, val - st[v * 2 + 1]);
}

void update(int v, int tl, int tr, int i)
{
    if (tl == tr)
    {
        st[v] = 0;
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

void solve()
{
    int n;
    cin >> n;
    vi nums(n);
    read_vi(nums, n);
    st.assign(4 * n, 0);

    build(1, 1, n);

    vi res(n + 1);

    for (int i = n - 1; i >= 0; i--)
    {
        int indice = query(1, 1, n, nums[i] + 1);
        res[i + 1] = indice;
        update(1, 1, n, indice);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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