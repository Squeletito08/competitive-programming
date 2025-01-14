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
    int n, m;
    cin >> n >> m;
    vll petya(n);
    vll vashia(m);

    read_vll(petya, n);
    read_vll(vashia, m);

    int a = 0;
    int b = n - 1;

    int c = 0;
    int d = m - 1;

    sort(all(petya));
    sort(all(vashia));

    ll suma = 0;

    while (a <= b)
    {
        if (abs(petya[a] - vashia[d]) >= abs(petya[b] - vashia[c]))
        {
            suma += abs(petya[a] - vashia[d]);
            a++;
            d--;
        }
        else
        {
            suma += (petya[b] - vashia[c]);
            b--;
            c++;
        }
    }

    cout << suma << endl;
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