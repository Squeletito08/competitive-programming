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

#define fore(i, a, b) for (int i = a, ThxDem = b; i < ThxDem; ++i)

int res = 0;

vll kmppre(vll &t)
{
  vll r(t.size() + 1);
  r[0] = -1;
  ll j = -1;
  fore(i, 0, t.size())
  {
    while (j >= 0 && t[i] != t[j])
      j = r[j];
    r[i + 1] = ++j;
  }
  return r;
}

ll kmp(vll &s, vll &t)
{

  ll res = 0;
  ll j = 0;
  vll b = kmppre(t);
  fore(i, 0, s.size())
  {
    while (j >= 0 && s[i] != t[j])
      j = b[j];
    if (++j == t.size())
      res++;
  }

  return res;
}

void solve()
{
  ll m, n;
  cin >> m >> n;

  vll diff;

  ll ant;
  cin >> ant;
  for (ll i = 1; i < m; i++)
  {
    ll act;
    cin >> act;
    diff.pb(act - ant);
    ant = act;
  }

  diff.pb(INF_LL);
  cin >> ant;
  for (ll i = 1; i < n; i++)
  {
    ll act;
    cin >> act;
    diff.pb(act - ant);
    ant = act;
  }

  vll pi = kmppre(diff);

  // cout << "pattern -> " << pattern << endl;
  // cout << "text -> " << text << endl;

  cout << count(all(pi), m - 1) << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}