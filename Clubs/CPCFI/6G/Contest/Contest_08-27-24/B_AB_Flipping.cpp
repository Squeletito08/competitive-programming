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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ctd = 0;
  int i = n - 1;
  int res = 0;
  while (i >= 0)
  {
    int ctdB = 1;
    int ctdA = 0;

    while (i >= 0 && s[i] == 'B')
    {
      i--;
      ctdB++;
    }

    while (i >= 0 && s[i] == 'A')
    {
      i--;
      ctdA++;
    }

    if (ctdB == 1 || ctdA == 0)
      continue;

    res += ctdB + ctdA - 1;
  }

  cout << max(res - 1, 0) << endl;
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