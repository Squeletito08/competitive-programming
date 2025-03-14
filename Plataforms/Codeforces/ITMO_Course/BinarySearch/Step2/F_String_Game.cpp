#include <bits/stdc++.h>
using namespace std;

#define owo                       \
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

string t, p;

bool good(int m, vi &perm)
{

    string aux = t;

    for (int i = 0; i < m; i++)
    {
        aux[perm[i] - 1] = 'X';
    }

    int n = sz(t);

    int j = 0;

    for (int i = 0; i < n && j < sz(p); i++)
    {
        if (p[j] == aux[i])
        {
            j++;
        }
    }

    return j == sz(p);
}

void solve()
{
    cin >> t >> p;

    int n = sz(t);

    vi perm(n);
    read_vi(perm, n);

    int l = 0;
    int r = n;

    int res = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (good(m, perm))
        {

            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
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