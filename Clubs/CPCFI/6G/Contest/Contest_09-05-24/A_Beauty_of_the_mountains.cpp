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
  int n, m, k;
  cin >> n >> m >> k;

  ll sum1 = 0;
  ll sum2 = 0;

  vvl nums(n, vll(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> nums[i][j];

  vvl mont(n + 2, vll(m + 2, 0));

  char c;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> c;
      mont[i][j] = (c == '0' ? 0 : 1);
      if (c == '0')
        sum1 += nums[i - 1][j - 1];
      else
        sum2 += nums[i - 1][j - 1];
      mont[i][j] += mont[i - 1][j] + mont[i][j - 1] - mont[i - 1][j - 1];
    }
  }

  if (sum1 == sum2)
  {
    cout << "YES" << endl;
    return;
  }

  error(sum1, sum2);

  for (int i = k; i <= n; i++)
  {
    for (int j = k; j <= m; j++)
    {

      ll x = mont[i][j] - mont[i - k][j] - mont[i][j - k] + mont[i - k][j - k];
      ll y = k * k - x;

      if (x - y == 0)
        continue;

      ll val = (sum2 - sum1) / (x - y);
      ll cant = (sum1 + (x * val)) - (sum2 + (y * val));

      error(x, y, val, cant);
      if (cant == 0)
      {
        cout << "YES" << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
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