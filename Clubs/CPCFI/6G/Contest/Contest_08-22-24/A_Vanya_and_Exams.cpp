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
  ll n, r, avg;
  cin >> n >> r >> avg;

  vector<pair<ll, ll>> exams(n);

  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    exams[i] = {b, a};
    sum += a;
  }

  if (sum / n >= avg)
  {
    cout << 0 << endl;
    return;
  }

  sort(all(exams));

  ll x = (avg * n) - sum;
  ll res = 0;
  int i = 0;
  while (x && i < n)
  {
    ll dif = min(x, r - exams[i].se);
    res += dif * exams[i].fi;
    x -= dif;
    i++;
  }

  cout << res << endl;
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