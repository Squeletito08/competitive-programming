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

int ask(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

void ans(vi &res)
{
    cout << "! ";
    for (int i = 1; i < sz(res); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void solve()
{

    int n;
    cin >> n;
    vi res(n + 1);

    int x = ask(1, 2);
    int y = ask(2, 3);
    int z = ask(1, 3);

    res[3] = (y - x + z) / 2;
    res[2] = y - res[3];
    res[1] = x - res[2];

    int a = res[1];

    for (int i = 4; i <= n; i++)
    {
        int sum = ask(1, i);
        res[i] = sum - a;
    }

    ans(res);
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