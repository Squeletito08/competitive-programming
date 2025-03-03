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

  vvl rab(n, vll(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> rab[i][j];
    }
  }

  vll S((1 << n), 0);

  for (int mask = 0; mask < (1 << n); mask++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (((1 << i) & mask) && ((1 << j) & mask))
        {
          S[mask] += rab[i][j];
        }
      }
    }
  }

  // for (int mask = 0; mask < (1 << n); mask++)
  // {
  //   bitset<8> bs(mask);
  //   cout << bs << " -> " << S[mask] << endl;
  // }

  vll dp((1 << n), 0);

  for (int mask = 0; mask < (1 << n); mask++)
  {
    for (int s = mask;; s = (s - 1) & mask)
    {

      if (s == 0)
      {
        dp[mask] = max(dp[mask], S[mask]);
        break;
      }

      int complemento = mask & ~(s);
      dp[mask] = max(dp[mask], dp[s] + S[complemento]);
    }
  }

  cout << dp[(1 << n) - 1] << endl;
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