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

  vector<pll> nums;

  for (int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    nums.emplace_back(a, b);
  }

  sort(all(nums), [](const pll &a, const pll &b) -> bool
       { return a.se < b.se; });

  int i = 0;
  int j = n - 1;

  ll total = 0;
  ll comprados = 0;

  while (i <= j)
  {

    ll a1 = nums[i].fi;
    ll b1 = nums[i].se;
    ll a2 = nums[j].fi;
    ll b2 = nums[j].se;

    if (b1 <= comprados)
    {
      total += a1;
      comprados += a1;
      i++;
      continue;
    }

    ll faltan = b1 - comprados;

    while (faltan && i <= j)
    {
      ll quito = min(faltan, nums[j].fi);
      nums[j].fi -= quito;
      comprados += quito;
      total += 2 * quito;
      faltan -= quito;

      if (nums[j].fi == 0)
        j--;
    }
  }

  cout << total << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}