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

void solve()
{
    long double c;
    cin >> c;

    long double l = 0;
    long double r = 1e6;

    long double m;

    cout << setprecision(16);

    for (int i = 0; i < 100; i++)
    {
        m = l + (r - l) / 2;
        long double val = m * m + sqrt(m);

        if (val == c)
        {
            cout << m << endl;
            return;
        }

        if (val < c)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    cout << m << endl;
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