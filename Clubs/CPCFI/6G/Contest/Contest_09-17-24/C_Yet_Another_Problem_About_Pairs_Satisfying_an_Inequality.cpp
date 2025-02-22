#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define fi first
#define se second
#define sz(a) int(a.size())
#define endl "\n"
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int tc;

#define error(args...)                            \
  {                                               \
    cerr << "--- Debug tc=" << tc << " ---" endl; \
    string _s = #args;                            \
    replace(_s.begin(), _s.end(), ',', ' ');      \
    stringstream _ss(_s);                         \
    istream_iterator<string> _it(_ss);            \
    err(_it, args);                               \
    cerr << endl;                                 \
  }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

template <typename T>
void read_v(vector<T> &a)
{
  for (int i = 0; i < a.size(); i++)
    cin >> a[i];
}

constexpr ll INF_LL = LONG_LONG_MAX;
constexpr int INF_INT = INT_MAX;
constexpr int MOD = 1e9 + 7;

vvi st;

void build(int v, int l, int r, vi &a)
{
  if (l == r)
  {
    st[v] = {a[l]};
    return;
  }

  int m = l + (r - l) / 2;
  build(v * 2, l, m, a);
  build(v * 2 + 1, m + 1, r, a);

  merge(all(st[v * 2]), all(st[v * 2 + 1]), back_inserter(st[v]));
}

int query(int v, int tl, int tr, int l, int r, int val)
{
  if (tl >= l && tr <= r)
  {
    return distance(upper_bound(all(st[v]), val), st[v].end());
  }

  if (tl > r || tr < l)
  {
    return 0;
  }

  int tm = tl + (tr - tl) / 2;

  return query(v * 2, tl, tm, l, r, val) + query(v * 2 + 1, tm + 1, tr, l, r, val);
}

void solve()
{
  int n;
  cin >> n;

  st = {};

  vi a;
  vi b;

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;

    if (x < i)
    {
      a.pb(x);
      b.pb(i);
    }
  }

  n = sz(a);

  if (n <= 1)
  {
    cout << 0 << endl;
    return;
  }

  st.resize(n * 4);
  build(1, 0, n - 1, a);

  ll res = 0;

  for (int i = 0; i < n; i++)
  {
    int val = query(1, 0, n - 1, i + 1, n - 1, b[i]);
    res += val;
  }

  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}