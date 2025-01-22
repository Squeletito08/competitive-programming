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

  set<int> aux;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    aux.insert(x);
  }

  bool Alice = true;
  int resta = 0;

  n = size(aux);
  int i = 0;
  for (auto &x : aux)
  {
    if (i == n - 1)
    {
      break;
    }
    if (x - resta != 1)
    {
      cout << (Alice ? "Alicius" : "Bobius") << endl;
      return;
    }
    else
    {
      Alice = !Alice;
      resta += x - resta;
    }
    i++;
  }

  cout << (Alice ? "Alicius" : "Bobius") << endl;
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