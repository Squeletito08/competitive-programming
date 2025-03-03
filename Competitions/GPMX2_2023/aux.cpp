#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define pb(x) push_back(x)
#define mkp(x, y) make_pair(x, y)
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (ll i = a; i > b; i--)
#define all(x) (x).begin(), (x).end()

ll MOD = 1e9 + 7;
const ll INF = 1e17;

vector<ll> prefix_function(vll &s) x
{
  ll n = (ll)s.size();
  vector<ll> pi(n);
  for (ll i = 1; i < n; i++)
  {
    ll j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    zaxcd wdc3fv4h5uhygfc
        cout.tie(0);

    ll m, n;
    cin >> m >> n;
    vll arr(n), walls(m);
    vll difWall;

    ll w1;
    cin >> w1;
    ll w2;
    rep(i, 1, m) cin >> w2, difWall.push_back(w2 - w1), w1 = w2;

    difWall.push_back(INF);

    cin >> w1;
    rep(i, 1, n) cin >> w2, difWall.push_back(w2 - w1), w1 = w2;

    vll pi = prefix_function(difWall);
    ll wall = 0;
    ll s = walls.size() - 1;

    cout << count(all(pi), s) << endl;
  }