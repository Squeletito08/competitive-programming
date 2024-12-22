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
const int INF = INT_MAX;

vi st_min;
vi st_max;

void build_min(int v, int tl, int tr, vi &nums)
{
    if (tl == tr)
    {
        st_min[v] = nums[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build_min(v * 2, tl, tm, nums);
    build_min(v * 2 + 1, tm + 1, tr, nums);

    st_min[v] = min(st_min[v * 2], st_min[v * 2 + 1]);
}

int query_min(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st_min[v];
    }

    if (tl > r || tr < l)
    {
        return INF;
    }

    int tm = (tl + tr) / 2;

    return min(query_min(v * 2, tl, tm, l, r), query_min(v * 2 + 1, tm + 1, tr, l, r));
}

void build_max(int v, int tl, int tr, vi &nums)
{
    if (tl == tr)
    {
        st_max[v] = nums[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build_max(v * 2, tl, tm, nums);
    build_max(v * 2 + 1, tm + 1, tr, nums);

    st_max[v] = max(st_max[v * 2], st_max[v * 2 + 1]);
}

int query_max(int v, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
    {
        return st_max[v];
    }

    if (tl > r || tr < l)
    {
        return -INF;
    }

    int tm = (tl + tr) / 2;

    return max(query_max(v * 2, tl, tm, l, r), query_max(v * 2 + 1, tm + 1, tr, l, r));
}

void solve()
{
    int n;
    cin >> n;

    vi nums(n);
    read_vi(nums, n);

    st_min.assign(4 * n, INF);
    st_max.assign(4 * n, -INF);

    build_min(1, 0, n - 1, nums);
    build_max(1, 0, n - 1, nums);

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int min_int = query_min(1, 0, n - 1, i, j);
        int max_int = query_max(1, 0, n - 1, i, j);

        if (nums[i] == min_int || nums[i] == max_int)
        {
            i++;
            continue;
        }

        if (nums[j] == min_int || nums[j] == max_int)
        {
            j--;
            continue;
        }

        cout << i + 1 << " " << j + 1 << endl;
        return;
    }

    cout << -1 << endl;
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