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
const ll INF = INT_MAX;

vi st;
vi nums;

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v] = nums[tl];
        return;
    }

    int tm = tl + (tr - tl) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    st[v] = st[v * 2] ^ st[v * 2 ^ 1];
}

int query(int v, int tl, int tr, int l, int r)
{
    if (l <= tl && r >= tr)
    {
        return st[v];
    }
    if (l > tr || r < tl)
    {
        return 0;
    }
    int tm = tl + (tr - tl) / 2;
    return query(v * 2, tl, tm, l, r) ^ query(v * 2 + 1, tm + 1, tr, l, r);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    nums.assign(n, 0);
    read_vi(nums, n);
    st.assign(n * 4, INF);

    build(1, 0, n - 1);

    while (q--)
    {
        int i, j;
        cin >> i >> j;
        cout << query(1, 0, n - 1, i - 1, j - 1) << endl;
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