#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
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

bool sePuede(ll num, ll m)
{

    if (num == m)
    {
        return true;
    }

    ll b = (2 * num) / 3;
    ll a = b / 2;

    if (b + a != num)
    {
        return false;
    }

    if (b == m || a == m)
    {
        return true;
    }

    return sePuede(b, m) || sePuede(a, m);
}

void solve()
{
    ll m, n;
    cin >> n >> m;

    if (sePuede(n, m))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}