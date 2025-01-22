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

  vi nums(5);
  cin >> nums[0];
  cin >> nums[1];
  cin >> nums[3];
  cin >> nums[4];

  nums[2] = nums[4] - nums[3];

  int ctd = 0;

  for (int i = 0; i < 3; i++)
  {
    if (nums[i] == nums[i + 2] - nums[i + 1])
      ctd++;
  }

  nums[2] = nums[0] + nums[1];

  int ctd2 = 0;
  for (int i = 0; i < 3; i++)
  {
    if (nums[i] == nums[i + 2] - nums[i + 1])
      ctd2++;
  }

  int ctd3 = 0;

  nums[2] = nums[3] - nums[1];

  for (int i = 0; i < 3; i++)
  {
    if (nums[i] == nums[i + 2] - nums[i + 1])
      ctd3++;
  }

  cout << max({ctd, ctd2, ctd3}) << endl;
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