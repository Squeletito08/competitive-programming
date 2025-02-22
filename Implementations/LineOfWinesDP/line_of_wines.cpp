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

vvi dp;
vi p;

// top-down
int max_profit(int l, int r, int n)
{
  if (dp[l][r] != -1)
    return dp[l][r];

  int y = n - r + l;

  if (l == r)
  {
    dp[l][r] = y * p[l]; // aquí y == n
    return dp[l][r];
  }

  dp[l][r] = max(y * p[l] + max_profit(l + 1, r, n),
                 y * p[r] + max_profit(l, r - 1, n));

  return dp[l][r];
}

// bottom-up
int max_profit(int n)
{
  int y = n;

  // Inicialización del caso base
  for (int k = 1; k <= n; k++)
    dp[k][k] = y * p[k];

  for (int k = 2; k <= n; k++)
  {
    for (int l = 1; l <= n - k + 1; l++)
    {
      int r = l + k - 1;
      y = n - r + l;
      dp[l][r] = max(y * p[l] + dp[l + 1][r], y * p[r] + dp[l][r - 1]);
    }
  }

  return dp[1][n];
}

void solve()
{

  int n;
  cin >> n;

  p.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  dp.resize(n + 2, vi(n + 2, -1));

  cout << "Para el arreglo: ";
  for (int i = 1; i <= n; i++)
    cout << p[i] << " ";

  cout << endl
       << "La ganancia máxima es: " << max_profit(n) << endl;

  cout << "Tabla de dp: " << endl;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
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