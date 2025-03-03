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

  vector<vector<ll>> nums(n + 2, vector<ll>(n + 2, -1));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> nums[i][j];
    }
  }

  ll ctd = 0;
  int inc = k - 1;

  for (int i = 1; i <= n - k + 1; i++)
  {
    for (int j = 1; j <= n - k + 1; j++)
    {

      unordered_set<int> aux;
      aux.insert(nums[i][j]);
      aux.insert(nums[i + inc][j]);
      aux.insert(nums[i][j + inc]);
      aux.insert(nums[i + inc][j + inc]);

      if (aux.size() == 1)
      {
        ctd++;
      }
      // cout << "i: " << i << endl;
      // cout << "j: " << j << endl;

      // cout << "i + k -1: " << i + k - 1 << endl;
      // cout << "j + k -1: " << j + k - 1 << endl;
    }
  }

  cout << ctd << endl;
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