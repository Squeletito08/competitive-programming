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

  vvi pares(27, vi(n + 1, 0));
  vvi impares(27, vi(n + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    char c;
    cin >> c;

    if (i % 2 == 0)
    {
      pares[c - 'a'][i]++;
    }
    else
    {
      impares[c - 'a'][i]++;
    }

    for (char x = 'a'; x <= 'z'; x++)
    {
      pares[x - 'a'][i] += pares[x - 'a'][i - 1];
      impares[x - 'a'][i] += impares[x - 'a'][i - 1];
    }
  }

  int maxPar = 0;
  int maxImpar = 0;

  if (n % 2 == 0)
  {

    for (char c = 'a'; c <= 'z'; c++)
    {
      maxPar = max(maxPar, pares[c - 'a'][n]);
      maxImpar = max(maxImpar, impares[c - 'a'][n]);
    }

    cout << n / 2 - maxPar + n / 2 - maxImpar << endl;
    return;
  }

  int minOp = INF_INT;

  for (int i = 1; i <= n; i++)
  {
    maxPar = 0;
    maxImpar = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
      int cantCPar = pares[c - 'a'][i - 1];
      int cantCImpar = impares[c - 'a'][i - 1];

      cantCPar += impares[c - 'a'][n] - impares[c - 'a'][i];
      cantCImpar += pares[c - 'a'][n] - pares[c - 'a'][i];

      maxPar = max(maxPar, cantCPar);
      maxImpar = max(maxImpar, cantCImpar);
    }

    int operaciones = n / 2 - maxPar + n / 2 - maxImpar;
    minOp = min(operaciones, minOp);
  }

  cout << minOp + 1 << endl;
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