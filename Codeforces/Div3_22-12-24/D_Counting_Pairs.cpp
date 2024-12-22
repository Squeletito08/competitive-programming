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

vector<vll> st;

void imprime(vll &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void build(int v, int tl, int tr, vll &nums)
{
    if (tl == tr)
    {
        st[v] = {nums[tl]};
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, nums);
    build(v * 2 + 1, tm + 1, tr, nums);

    merge(all(st[v * 2]), all(st[v * 2 + 1]), back_inserter(st[v]));
}

ll query(int v, int tl, int tr, int l, int r, ll a, ll b)
{
    if (tl >= l && tr <= r)
    {

        // cout << "tl -> " << tl << endl;
        // cout << "tr -> " << tr << endl;
        // imprime(st[v]);

        ll x = distance(lower_bound(all(st[v]), a), upper_bound(all(st[v]), b));
        // cout << "en este intervalo dis es: " << x << endl;
        return x;
    }

    if (tl > r || tr < l)
    {
        return 0;
    }

    int tm = (tl + tr) / 2;

    return query(v * 2, tl, tm, l, r, a, b) + query(v * 2 + 1, tm + 1, tr, l, r, a, b);
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll sum = 0;
    vll nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    st.assign(4 * n, vll{});

    build(1, 0, n - 1, nums);

    ll res = 0;

    for (int i = 0; i < n - 1; i++)
    {

        sum -= nums[i];

        // cout << "num -> " << nums[i] << endl;
        ll a = sum - y, b = sum - x;

        // cout << "a -> " << a << endl;
        // cout << "b -> " << b << endl;

        ll dis = query(1, 0, n - 1, i + 1, n - 1, a, b);
        // cout << "dis _> " << dis << endl;
        res += dis;

        sum += nums[i];
    }

    cout << res << endl;
}

int main()
{
    owo

        int tt = 1;
    cin >> tt;

    while (tt--)
    {
        solve();
    }

    return 0;
}