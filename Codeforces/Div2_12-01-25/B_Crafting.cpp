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
    int n;
    cin >> n;

    vll a(n);
    vll b(n);

    read_vll(a, n);
    read_vll(b, n);

    ll ctd = 0;
    ll minimo = INF;
    ll dif = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            ctd++;
            dif = b[i] - a[i];
        }
        else
        {
            minimo = min(minimo, a[i] - b[i]);
        }
    }

    if (ctd > 1)
    {
        cout << "NO" << endl;
        return;
    }

    if (ctd == 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (dif <= minimo)
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
    owo

        int tt = 1;
    cin >> tt;

    while (tt--)
    {
        solve();
    }

    return 0;
}