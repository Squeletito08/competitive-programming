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

vector<int> a = {1, 2, 3, 4, 5, 6};
vector<int> b = {-10, 1, 2, -20, -30};
vector<int> c = {1, -2, 3, -4, 5, -6};
vector<int> d = {-1, -2, -3, -4, -5 - 6};
vector<vector<int>> test = {a, b, c, d};

void printAnswer(int ans, int l, int r, vector<int> &v)
{
  cout << "Para el arreglo: " << endl;
  for (auto x : v)
    cout << x << " ";
  cout << endl;
  cout << "La respuesta es: " << ans << endl;
  cout << "En el subarreglo: [" << l << ", " << r << "]" << endl
       << endl;
}

void algorithm1(vector<int> &v)
{
  int ans = v[0];
  int sum = 0;
  int min_sum = 0;
  int min_pos = -1;
  int l = 0;
  int r = 0;

  for (int i = 0; i < sz(v); i++)
  {
    sum += v[i];

    int current = sum - min_sum;

    if (current > ans)
    {
      ans = current;
      l = min_pos + 1;
      r = i;
    }

    if (sum < min_sum)
    {
      min_sum = sum;
      min_pos = i;
    }
  }

  printAnswer(ans, l, r, v);
}

void algorithm2(vector<int> &v)
{
  int ans = v[0];
  int l = 0;
  int r = 0;
  int min_pos = -1;
  int sum = 0;

  for (int i = 0; i < sz(v); i++)
  {
    sum += v[i];

    if (sum > ans)
    {
      ans = sum;
      r = i;
      l = min_pos + 1;
    }

    if (sum < 0)
    {
      sum = 0;
      min_pos = i;
    }
  }

  printAnswer(ans, l, r, v);
}

void solve()
{

  cout << "Con algoritmo 1: " << endl
       << endl;
  for (int i = 0; i < sz(test); i++)
  {
    algorithm1(test[i]);
  }

  cout << endl;

  cout << "Con el algoritmo 2: " << endl
       << endl;
  for (int i = 0; i < sz(test); i++)
  {
    algorithm2(test[i]);
  }
  cout << endl;
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