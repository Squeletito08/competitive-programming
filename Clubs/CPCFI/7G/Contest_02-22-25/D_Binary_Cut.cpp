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
  string s;
  cin >> s;
  int ctd = 1;

  int i = 0;
  int n = sz(s);

  int a = -1;
  int b = -1;

  int maximo = INT_MIN;

  while (i < n)
  {

    int tam = 1;

    if (s[i] != '0')
    {
      i++;
      continue;
    }

    while (i + 1 < n && s[i + 1] == '0')
    {
      i++;
      tam++;
    }

    if (i == n - 1)
    {
      break;
    }

    while (i + 1 < n && s[i + 1] == '1')
    {
      i++;
      tam++;
    }

    if (tam > maximo)
    {
      a = i - tam + 1;
      b = i;
      maximo = tam;
    }

    i++;
  }

  if (a == -1 && b == -1)
  {
    int aux = 0;

    i = 0;

    while (i < n)
    {
      if (s[i] == '0')
      {
        while (i + 1 < n && s[i + 1] == '0')
          i++;
        aux++;
      }
      else
      {
        while (i + 1 < n && s[i + 1] == '1')
          i++;
        aux++;
      }
      i++;
    }
    cout << aux << endl;
    return;
  }

  i = 0;

  while (i < a)
  {
    if (s[i] == '0')
    {
      while (i + 1 < n && s[i + 1] == '0')
        i++;
      ctd++;
    }
    else
    {
      while (i + 1 < n && s[i + 1] == '1')
        i++;
      ctd++;
    }
    i++;
  }

  i = b + 1;

  while (i < n)
  {
    if (s[i] == '0')
    {
      while (i + 1 < n && s[i + 1] == '0')
        i++;
      ctd++;
    }
    else
    {
      while (i + 1 < n && s[i + 1] == '1')
        i++;
      ctd++;
    }
    i++;
  }

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