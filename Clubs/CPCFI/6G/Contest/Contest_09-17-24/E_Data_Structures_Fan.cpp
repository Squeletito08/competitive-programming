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

  vi nums(n);
  read_v(nums);

  string s;
  cin >> s;
  vi prefix(n + 1);

  int x_0 = 0;
  int x_1 = 0;

  for (int i = 1; i <= n; i++)
  {
    prefix[i] = prefix[i - 1] ^ nums[i - 1];

    if (s[i - 1] == '0')
      x_0 ^= nums[i - 1];
    else
      x_1 ^= nums[i - 1];
  }

  int q;
  cin >> q;

  while (q--)
  {
    int op;
    cin >> op;

    if (op == 1)
    {
      int l, r;
      cin >> l >> r;

      x_0 ^= prefix[r] ^ prefix[l - 1];
      x_1 ^= prefix[r] ^ prefix[l - 1];
    }
    else
    {
      char c;
      cin >> c;

      cout << (c == '0' ? x_0 : x_1) << " ";
    }
  }

  cout << endl;
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