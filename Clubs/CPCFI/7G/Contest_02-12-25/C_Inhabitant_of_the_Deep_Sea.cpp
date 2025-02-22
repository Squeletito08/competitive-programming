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
  ll n, k;
  cin >> n >> k;
  vll nums(n);
  read_v(nums);

  int i = 0;
  int j = n - 1;
  int ctd = 0;

  while (i < j && k)
  {
    ll m = min(nums[i], nums[j]);

    if (k < 2 * m)
    {
      nums[i] -= k / 2 + k % 2;
      nums[j] -= k / 2;
      k = 0;
    }
    else
    {
      nums[i] -= m;
      nums[j] -= m;
      k -= 2 * m;
    }

    if (nums[i] == 0)
    {
      i++;
      ctd++;
    }

    if (nums[j] == 0)
    {
      j--;
      ctd++;
    }
  }

  if (i == j && k >= nums[i])
    ctd++;

  cout << ctd << endl;
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