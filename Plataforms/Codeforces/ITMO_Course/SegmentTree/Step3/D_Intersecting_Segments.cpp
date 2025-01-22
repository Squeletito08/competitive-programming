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

void update(int v, int tl, int tr, int pos, int val)
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

    if (tr < l || tl > r)
    {
        return 0;
    }

    int tm = tl + (tr - tl) / 2;

    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

void solve()
{
    int n;
    cin >> n;

    vi res(n + 1);

    n *= 2;

    vi nums(n);
    read_vi(nums, n);
    st.assign(4 * n, 0);

    map<int, int> mapa;

    for (int i = 0; i < n; i++)
    {

        int x = nums[i];
        if (!mapa.count(x))
        {
            update(1, 0, n - 1, i, 1);
            mapa[x] = i;
        }
        else
        {
            int j = mapa[x];
            update(1, 0, n - 1, j, 0);
            res[x] = query(1, 0, n - 1, j, i);
        }
    }

    reverse(all(nums));

    mapa.clear();

    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        if (!mapa.count(x))
        {
            update(1, 0, n - 1, i, 1);
            mapa[x] = i;
        }
        else
        {
            int j = mapa[x];
            update(1, 0, n - 1, j, 0);
            res[x] += query(1, 0, n - 1, j, i);
        }
    }

    for (int i = 1; i <= n / 2; i++)
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