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

void dfs(vvi &graph, vector<bool> &vis, vi &g, int u, map<int, int> &aux, vi &res)
{
  vis[u] = true;
  aux[g[u]]++;

  // cout << "u -> " << u << endl;
  // for (auto [k, v] : aux)
  // {
  //   cout << k << " -> " << v << endl;
  // }

  cout << endl;

  for (auto v : graph[u])
  {
    if (!vis[v])
    {
      dfs(graph, vis, g, v, aux, res);
    }
  }

  res[u] = aux.size();

  if (aux[g[u]] == 1)
  {
    aux.erase(g[u]);
  }
  else
  {
    aux[g[u]]--;
  }
}

void solve()
{
  int n;
  cin >> n;

  vvi graph(n + 1);
  vi g(n + 1);
  vector<bool> vis(n + 1);
  vi res(n + 1);

  int raiz = -1;

  for (int u = 1; u <= n; u++)
  {
    int v;
    cin >> v;

    if (v == 0)
    {
      raiz = u;
      continue;
    }
    graph[v].pb(u);
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> g[i];
  }

  map<int, int> aux;
  dfs(graph, vis, g, raiz, aux, res);

  for (int i = 1; i <= n; i++)
  {
    cout << res[i] << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;

  for (tc = 1; tc <= t; tc++)
    solve();

  return 0;
}