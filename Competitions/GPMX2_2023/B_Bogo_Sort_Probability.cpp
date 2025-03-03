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

ll powmod(ll base, ll exp)
{
  base %= MOD;
  ll res = 1;
  while (exp > 0)
  {
    if (exp & 1)
    {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return res;
}

ll inverse_mod(ll x)
{
  return powmod(x, MOD - 2);
}

ll factorial(ll n)
{
  ll res = 1;

  while (n > 1)
  {
    res = (res * powmod(MOD - 1, n / MOD)) % MOD;
    for (int i = 2; i <= n % MOD; ++i)
    {
      res = (res * i) % MOD;
    }
    n /= MOD;
  }

  return res % MOD;
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vi nums(n);
  read_v(nums);

  map<int, int> aux;
  for (int i = 0; i < n; i++)
  {
    aux[nums[i]]++;
  }

  ll p = n - aux.size() + 1;

  ll q = inverse_mod(factorial(n));

  cout << (p * q) % MOD << endl;

  while (k--)
  {
    int a, b;
    cin >> a >> b;
    a--;

    // cout << "anttes map -> " << endl;

    // for (auto [x, v] : aux)
    // {
    //   cout << x << ", " << v << endl;
    // }

    aux[nums[a]]--;
    aux[b]++;

    if (aux[nums[a]] == 0)
    {
      aux.erase(nums[a]);
    }

    // cout << "map -> " << endl;

    // for (auto [x, v] : aux)
    // {
    //   cout << x << ", " << v << endl;
    // }

    // cout << "aux.size -> " << aux.size() << endl;

    nums[a] = b;

    p = n - aux.size() + 1;

    // error(p, q);

    if (p == n)
    {
      cout << 1 << endl;
      continue;
    }

    cout
        << (p % MOD * q % MOD) % MOD << endl;
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