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

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vi> vacas(n, vi(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> vacas[i][j];
    }

    sort(all(vacas[i]));
  }

  bool si = true;

  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (vacas[i][j] - n != vacas[i][j - 1])
      {
        si = false;
      }
    }
  }

  if (!si)
  {
    cout << -1 << endl;
    return;
  }

  vi perm(n);

  for (int i = 0; i < n; i++)
  {
    perm[vacas[i][0]] = i;
  }

  for (auto x : perm)
    cout << x + 1 << " ";

  cout << endl;
}

int main()
{
  owo

      int tt = 1;
  cin >> tt;

  while (tt--)
  {
    solve();
  }

  return 0;
}