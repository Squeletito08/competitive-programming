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

ll suma_dig(ll num)
{
    ll res = 0;

    while (num)
    {
        res += num % 10;
        num /= 10;
    }

    return res;
}

vll prefix(2e5 + 10);

void solve()
{
    ll n;
    cin >> n;

    cout << prefix[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i = 1; i < 2e5 + 10; i++)
    {
        prefix[i] = prefix[i - 1] + suma_dig(i);
    }
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}