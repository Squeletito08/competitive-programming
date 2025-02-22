#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 3e5 + 50;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

ll pow_mod(ll x, ll n, ll mod)
{
  ll res = 1;
  while (n)
  {
    if (n & 1)
      res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
ll inv(ll a, ll p) { return pow_mod(a, p - 2, p); }
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  ll ans = 0;
  for (int i = 0; i < m; i++)
  {
    ans += pow_mod(c, n * n * __gcd(i, m), mod);
    ans %= mod;
  }
  cout << ans * inv(m, mod) % mod << endl;
  return 0;
}