#include <bits/stdc++.h>
using namespace std;

#define owo                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void read_vi(vi &a, int n)
{
  for (int i = 0; i < n; i++)
    cin >> a[i];
}
void read_vll(vll &a, int n)
{
  for (int i = 0; i < n; i++)
    cin >> a[i];
}
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool esCruz(vector<vector<char>> &m, int i, int j)
{
  return m[i][j] == '#' && m[i - 1][j] == '#' && m[i + 1][j] == '#' && m[i][j - 1] == '#' && m[i][j + 1] == '#';
}
void solve()
{
  int n;
  cin >> n;

  int ctd = 0;

  int ctd2 = 0;
  vector<vector<char>> m(n + 2, vector<char>(n + 2, '.'));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      char c;
      cin >> c;
      if (c == '#')
        ctd++;
      m[i][j] = c;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (m[i][j] == '#' && esCruz(m, i, j))
      {
        ctd2++;
        m[i][j] = m[i - 1][j] = m[i + 1][j] = m[i][j - 1] = m[i][j + 1] = '.';
      }
    }
  }

  if (ctd2 * 5 == ctd)
  {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
}

int main()
{
  owo

      int tt = 1;

  while (tt--)
  {
    solve();
  }

  return 0;
}