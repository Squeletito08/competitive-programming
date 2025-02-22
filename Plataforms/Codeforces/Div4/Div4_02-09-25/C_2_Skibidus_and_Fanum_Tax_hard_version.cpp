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

int bs(int l, int r, vi &b_v, int act, int ant)
{
  int ind = 0;

  while (l <= r)
  {
    int mid = l + (r - l) / 2;

    if (b_v[mid] - act >= ant)
    {
      r = mid - 1;
      ind = mid;
    }
    else
    {
      l = mid + 1;
    }
  }

  return ind;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vi a_v(n);
  read_v(a_v);

  vi b_v(m);
  read_v(b_v);

  sort(all(b_v));

  int ind = bs(0, m - 1, b_v, a_v[0], -INF_INT);
  a_v[0] = min(b_v[ind] - a_v[0], a_v[0]);

  bool good = true;
  for (int i = 1; i < n; i++)
  {

    int ind = bs(0, m - 1, b_v, a_v[i], a_v[i - 1]);

    int val_min = min(b_v[ind] - a_v[i], a_v[i]);
    int val_max = max(b_v[ind] - a_v[i], a_v[i]);

    if (val_min >= a_v[i - 1])
    {
      a_v[i] = val_min;
      continue;
    }

    if (val_max >= a_v[i - 1])
    {
      a_v[i] = val_max;
      continue;
    }

    good = false;
  }

  cout << (good ? "YES" : "NO") << endl;
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