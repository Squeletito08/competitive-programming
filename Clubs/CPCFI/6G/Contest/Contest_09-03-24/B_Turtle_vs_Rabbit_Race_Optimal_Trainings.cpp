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

ll val_max(ll u, ll l, ll r, vll &prefix, ll rest)
{

  // ll target = u + rest;
  // auto it = lower_bound(prefix.begin() + l, prefix.begin() + r + 1, target);

  ll target = u;
  auto it = lower_bound(prefix.begin() + l, prefix.begin() + r + 1, target, [&](ll value, ll target)
                        { return (value - rest) < target; });

  ll ind = it - prefix.begin();

  ll curr = prefix[ind] - rest;

  if (ind > l)
  {
    ll ant = prefix[ind - 1] - rest;

    curr = u * curr - (curr * (curr - 1)) / 2;
    ant = u * ant - (ant * (ant - 1)) / 2;

    if (ant >= curr)
      ind = max(1ll, ind - 1);
  }

  return ind;
}

void solve()
{
  int n;
  cin >> n;
  vll nums(n);
  vll prefix(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
    prefix[i + 1] = prefix[i] + nums[i];
  }

  int q;
  cin >> q;

  while (q--)
  {
    ll l, u;
    cin >> l >> u;

    ll ind = val_max(u, l, n, prefix, prefix[l - 1]);
    cout << ind << " ";
  }

  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}