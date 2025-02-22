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
  int n, m;
  cin >> n >> m;

  vi a_v(n);
  read_v(a_v);

  vi b_v(m);
  read_v(b_v);

  sort(all(b_v));
  bool good = true;

  a_v[0] = min(b_v[m - 1] - a_v[0], a_v[0]);

  for (int i = 1; i < n; i++)
  {

    int l = 0;
    int r = m - 1;

    int val = -INF_INT;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      int min_val = min(b_v[mid] - a_v[i], a_v[i]);
      int max_val = max(b_v[mid] - a_v[i], a_v[i]);

      if (min_val >= a_v[i - 1])
      {
        r = mid - 1;
        val = min_val;
      }
      else if (max_val >= a_v[i - 1])
      {
        r = mid - 1;
        val = max_val;
      }
      else
      {
        l = mid + 1;
      }
    }

    if (val == -INF_INT)
    {
      cout << "NO" << endl;
      return;
    }

    a_v[i] = val;
  }

  cout << "YES" << endl;
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