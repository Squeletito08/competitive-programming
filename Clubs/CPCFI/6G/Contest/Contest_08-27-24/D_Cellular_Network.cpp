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

    vll a(n), b(m);
    read_vll(a, n);
    read_vll(b, m);

    ll min_dif = INF;
    ll res = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while ((j < m - 1) && b[j + 1] <= a[i])
            j++;

        int sig = (j < m - 1) ? b[j + 1] : b[j];

        res = max(res, min(abs(a[i] - b[j]), abs(a[i] - sig)));
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