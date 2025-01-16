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
    vi a(n);
    vi b(m);
    read_vi(a, n);
    read_vi(b, m);

    int i = 0;
    int j = 0;

    vi c(n + m);

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[i + j] = a[i];
            i++;
        }
        else
        {
            c[i + j] = b[j];
            j++;
        }
    }

    while (i < n)
    {
        c[i + j] = a[i];
        i++;
    }

    while (j < m)
    {
        c[i + j] = b[j];
        j++;
    }

    for (auto x : c)
        cout << x << " ";

    cout << endl;
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