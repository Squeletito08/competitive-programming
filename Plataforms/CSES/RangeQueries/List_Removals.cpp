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

    ST(int n)
    {
        st.assign(n * 4, 1);
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            return;
        }

        int tm = tl + (tr - tl) / 2;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        st[v] = st[v * 2] + st[v * 2 + 1];
    }

    int query(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
        {
            return tl;
        }

        int tm = (tr + tl) / 2;

        return (st[v * 2] >= pos) ? query(v * 2, tl, tm, pos) : query(v * 2 + 1, tm + 1, tr, pos - st[v * 2]);
    }

    void update(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
        {
            st[v] = 0;
            return;
        }

        int tm = tl + (tr - tl) / 2;

        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos);
        }

        st[v] = st[v * 2] + st[v * 2 + 1];
    }
};

void solve()
{
    int n;
    cin >> n;

    vi nums(n);
    read_vi(nums, n);

    ST st{n};

    int x = n;

    while (x--)
    {
        int i;
        cin >> i;

        int res = st.query(1, 0, n - 1, i);
        cout << nums[res] << " ";
        st.update(1, 0, n - 1, res);
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