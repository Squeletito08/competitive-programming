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

ll lcm_f(ll a, ll b)
{
  return abs(a / gcd(a, b) * b);
}

void solve()
{
  int n;
  cin >> n;
  ll m = INT_MIN;

  vll nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
    m = max(m, nums[i]);
  }

  if (n == 1)
  {
    cout << 1 << endl;
    return;
  }

  vll diffs(n);

  for (int i = 0; i < n; i++)
  {
    diffs[i] = m - nums[i];
  }

  ll gcd_a = 0;
  for (int i = 0; i < n; i++)
  {
    gcd_a = gcd(gcd_a, diffs[i]);
  }

  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    res += diffs[i] / gcd_a;
  }

  set<ll> aux_nums(all(nums));

  ll j = 0;
  ll buscar = m;
  while (aux_nums.count(buscar))
  {
    j++;
    buscar -= gcd_a;
  }

  res = min(res + n, res + j);

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