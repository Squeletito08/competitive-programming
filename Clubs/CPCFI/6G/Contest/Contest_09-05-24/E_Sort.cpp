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
  int n, q;
  cin >> n >> q;

  string a, b;
  cin >> a >> b;

  vvi m_a(27, vi(n + 1, 0));
  vvi m_b(27, vi(n + 1, 0));

  unordered_map<char, int> mapeo;

  int ctd = 0;
  for (char c = 'a'; c <= 'z'; c++)
  {
    mapeo[c] = ctd;
    ctd++;
  }

  for (char c = 'a'; c <= 'z'; c++)
  {
    int i = mapeo[c];
    for (int j = 1; j <= n; j++)
    {
      m_a[i][j] += m_a[i][j - 1] + (a[j - 1] == c ? 1 : 0);
      m_b[i][j] += m_b[i][j - 1] + (b[j - 1] == c ? 1 : 0);
    }
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;

    int dif = 0;

    for (char c = 'a'; c <= 'z'; c++)
    {
      int i = mapeo[c];

      int cant_a = m_a[i][r] - m_a[i][l - 1];
      int cant_b = m_b[i][r] - m_b[i][l - 1];

      dif += min(cant_a, cant_b);
    }

    cout << (r - l + 1) - dif << endl;
  }
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