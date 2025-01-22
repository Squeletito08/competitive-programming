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

void build(int v, int tl, int tr, bool op_xor, vi &nums)
{
    if (tl == tr)
    {
        st[v] = nums[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, !op_xor, nums);
    build(v * 2 + 1, tm + 1, tr, !op_xor, nums);
    st[v] = (op_xor ? st[v * 2] ^ st[v * 2 + 1] : st[v * 2] | st[v * 2 + 1]);
}

void update(int v, int tl, int tr, int p, int b, bool op_xor)
{
    if (tl == tr)
    {
        st[v] = b;
        return;
    }

    int tm = (tl + tr) / 2;

    if (p <= tm)
    {
        update(v * 2, tl, tm, p, b, !op_xor);
    }
    else
    {
        update(v * 2 + 1, tm + 1, tr, p, b, !op_xor);
    }

    st[v] = (op_xor ? st[v * 2] ^ st[v * 2 + 1] : st[v * 2] | st[v * 2 + 1]);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    n = (1 << n);
    st.assign(4 * n, 0);
    vi nums(n);
    read_vi(nums, n);

    bool op_xor = ((int)ceil(log2(n)) % 2 == 0);

    build(1, 0, n - 1, op_xor, nums);

    while (m--)
    {
        int p, b;
        cin >> p >> b;

        update(1, 0, n - 1, p - 1, b, op_xor);

        cout << st[1] << endl;
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