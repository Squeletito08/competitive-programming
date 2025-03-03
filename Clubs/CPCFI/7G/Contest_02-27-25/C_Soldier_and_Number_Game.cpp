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

int MAX_N = 1e7;
vector<int> sieve(MAX_N);
vector<ll> prime_factors(MAX_N);
vector<ll> prefix(MAX_N + 1);

void criba()
{
  for (int i = 2; i <= MAX_N; i++)
  {
    if (sieve[i] == 0)
    {
      for (int j = i; j <= MAX_N; j += i)
        sieve[j] = i;
    }
  }
}

void solve()
{
  int a, b;
  cin >> a >> b;

  cout << prefix[a] - prefix[b] << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;

  criba();

  for (int i = 2; i < MAX_N; i++)
  {
    prime_factors[i] = prime_factors[i / sieve[i]] + 1;
  }

  for (int i = 1; i <= MAX_N; i++)
  {
    prefix[i] = prefix[i - 1] + prime_factors[i];
  }

  // cout << "criba -> " << endl;
  // for (int i = 0; i < 100; i++)
  // {
  //   cout << i << "-> " << sieve[i] << endl;
  // }
  // cout << "prime factores -> " << endl;
  // for (int i = 0; i < 100; i++)
  // {
  //   cout << i << "-> " << prime_factors[i] << endl;
  // }

  // cout << "Prefix: " << endl;
  // for (int i = 0; i < 100; i++)
  // {
  //   cout << i << " -> " << prefix[i] << endl;
  // }

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}