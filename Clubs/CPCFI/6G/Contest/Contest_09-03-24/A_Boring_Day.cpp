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
  ll n, l, r;
  cin >> n >> l >> r;

  vll cards(n);
  read_v(cards);

  vll pref(n + 1);
  for (int i = 1; i <= n; i++)
    pref[i] += pref[i - 1] + cards[i - 1];

  ll ctd = 0;

  for (int i = 1; i <= n; i++)
  {

    ll l_aux = i;
    ll r_aux = n;

    ll rest = pref[i - 1];

    ll res = -1;
    while (l_aux <= r_aux)
    {
      ll mid = (l_aux + r_aux) / 2;

      if (pref[mid] - rest >= l)
      {
        res = mid;
        r_aux = mid - 1;
      }
      else
      {
        l_aux = mid + 1;
      }

      error(l_aux, r_aux, rest, res);
    }

    if (res == -1 || pref[res] - rest > r)
      continue;

    ctd++;
    i = res;
  }
  cout << ctd << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}