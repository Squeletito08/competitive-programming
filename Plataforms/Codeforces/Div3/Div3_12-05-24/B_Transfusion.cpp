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
    ll n;
    cin >> n;
    vll nums(n);
    ll suma1 = 0;
    ll suma2 = 0;
    int ctd = 0;
    int ctd2 = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if (i % 2 == 0)
        {
            suma1 += x;
            ctd++;
        }
        else
        {
            suma2 += x;
            ctd2++;
        }
    }

    long double m1 = (long double)suma1 / (long double)ctd;
    long double m2 = (long double)suma2 / (long double)(ctd2);

    ll aux1 = (ll)m1;
    ll aux2 = (ll)m2;

    if (m1 - aux1 != 0 || m2 - aux2 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    cout << (m1 == m2 ? "YES" : "NO") << endl;
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