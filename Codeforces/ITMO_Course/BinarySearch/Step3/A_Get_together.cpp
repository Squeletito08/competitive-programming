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

bool good(double t, vector<pair<double, double>> &values)
{

    double producto = t * values[0].se;
    double a = -1e10;
    double b = 1e10;

    for (int i = 0; i < sz(values); i++)
    {

        producto = t * values[i].se;
        a = max(values[i].fi - producto, a);
        b = min(values[i].fi + producto, b);
    }

    return b > a;
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<double, double>> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i].fi;
        cin >> values[i].se;
    }

    double l = 0;
    double r = 1e10;

    double res = 0;
    for (int i = 0; i < 100; i++)
    {
        double m = (r + l) / 2;

        if (good(m, values))
        {
            res = m;
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << setprecision(10);

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