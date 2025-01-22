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

void update(int v, int tl, int tr, int i, ll val)
{
    if (tl == tr)
    {
        st[v] = val;
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

    int tm = (tl + tr) / 2;

    return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

void solve()
{
    int n;
    cin >> n;
    vector<pll> nums(n);

    st.assign(4 * n, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i] = {x, i};
    }

    int q;
    cin >> q;
    vector<vll> querys;

    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        querys.pb({k, l, r, i});
    }

    sort(rall(nums));
    sort(rall(querys));

    vll res(q);

    int j = 0;

    for (int i = 0; i < q; i++)
    {

        ll k = querys[i][0];
        int l = querys[i][1];
        int r = querys[i][2];

        while (j < n && nums[j].fi > k)
        {
            update(1, 0, n - 1, nums[j].se, 1);
            j++;
        }

        res[querys[i][3]] = query(1, 0, n - 1, l, r);
    }

    for (auto x : res)
    {
        cout << x << endl;
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