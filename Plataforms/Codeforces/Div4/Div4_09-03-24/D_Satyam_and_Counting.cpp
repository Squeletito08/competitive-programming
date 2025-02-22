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

void solve()
{
  int n;
  cin >> n;

  vector<pii> points;
  vector<bool> line_0(n + 1, false);
  vector<bool> line_1(n + 1, false);

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);

    if (y == 0)
      line_0[x] = true;

    if (y == 1)
      line_1[x] = true;
  }

  ll res1 = 0;
  ll res2 = 0;
  sort(all(points));

  for (int i = 0; i < n; i++)
  {
    auto [x, y] = points[i];

    if (y == 0 && line_1[x] || y == 1 && line_0[x])
      res1 += n - 2;

    if ((y == 0 && x >= 1 && line_1[x - 1] && x <= n - 1 && line_1[x + 1]) || (y == 1 && x >= 1 && line_0[x - 1] && x <= n - 1 && line_0[x + 1]))
      res2++;
  }
  cout << res1 / 2 + res2 << endl;
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