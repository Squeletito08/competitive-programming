#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;

ll MOD = 1000000007;

ll mod(ll a, ll m)
{
  return ((a % m) + m) % m;
}

vvl mult_por_vector(vvl &A, vvl &v)
{
  int rowA = A.size();
  int colB = v[0].size();
  int colA = A[0].size();

  int n = v.size();
  vvl C(n, vector<ll>(v[0].size(), 0));

  for (int i = 0; i < rowA; i++)
  {
    for (int j = 0; j < colB; j++)
    {
      for (int k = 0; k < colA; k++)
      {
        ll aux = (A[i][k] * v[k][j]) % MOD;
        C[i][j] += aux;
        C[i][j] %= MOD;
      }
    }
  }

  return C;
}

vvl matPow(vvl &base, int p)
{

  int n = base.size();
  int m = base[0].size();
  vvl ans(n, vector<ll>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == j)
      {
        ans[i][j] = 1;
      }
    }
  }
  while (p)
  {
    if (p & 1)
    {
      ans = mult_por_vector(ans, base);
    }
    base = mult_por_vector(base, base);
    p >>= 1;
  }

  return ans;
}

ll fibo(ll n)
{
  vvl base = {{1, 1}, {1, 0}};

  vvl fib_m = matPow(base, n);

  return fib_m[0][1];
}

void solve()
{

  ll n, m;
  cin >> n >> m;

  ll a = fibo(m + 2);
  ll b = fibo(n + 1);

  cout << (a - b) % MOD << endl;
}

int main()
{

  // ios::sync_with_studio(false);
  // cin.tie(0);

  int t;
  t = 1;

  cin >> t;

  while (t--)
  {
    solve();
  }
}