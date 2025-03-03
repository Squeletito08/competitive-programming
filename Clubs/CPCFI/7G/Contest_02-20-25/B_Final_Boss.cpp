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

bool good(vll &a, vll &c, ll k, ll h)
{

  ll res = 0;
  for (int i = 0; i < sz(a) && res < h; i++)
  {
    ll ctd = (k / c[i]) + 1;

    if (ctd >= h)
    {
      return true;
    }

    res += a[i] * ctd;
  }

  return res >= h;
}

void solve()
{
  ll h, n;
  cin >> h >> n;
  vll a(n);
  read_v(a);
  vll c(n);
  read_v(c);

  ll l = 1;
  ll r = 1e13;

  ll res = INF_LL;
  while (l <= r)
  {
    ll mid = (l + r) / 2;

    if (good(a, c, mid - 1, h))
    {
      res = min(res, mid);
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
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