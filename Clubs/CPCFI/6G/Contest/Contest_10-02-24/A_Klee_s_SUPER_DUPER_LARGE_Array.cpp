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

ll value_a(ll k, ll i)
{
  return (k + i) * (k + i + 1) / 2;
}

ll value_b(ll k)
{
  return (k - 1) * k / 2;
}

ll value_c(ll k, ll i, ll n)
{
  return (k + n - 1) * (k + n) / 2;
}

ll from0_to_i(ll k, ll i, ll n)
{
  return value_a(k, i) - value_b(k);
}

ll from_i_to_n(ll k, ll i, ll n)
{
  return value_c(k, i, n) - value_a(k, i);
}

ll value(ll k, ll i, ll n)
{
  return abs(from0_to_i(k, i, n) - from_i_to_n(k, i, n));
}

void solve()
{
  ll n, k;
  cin >> n >> k;

  ll max_i = -INF_INT;

  ll l = 0;
  ll r = n - 1;

  while (l <= r)
  {
    ll mid = l + (r - l) / 2;

    ll x = from0_to_i(k, mid, n);
    ll y = from_i_to_n(k, mid, n);

    if (x <= y)
    {
      max_i = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }

  ll res = value(k, max_i, n);

  cout << min(res, value(k, min(max_i + 1, n), n)) << endl;
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