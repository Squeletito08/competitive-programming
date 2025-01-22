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

void ask(int x)
{
    cout << x << endl;
}

void ans(int x)
{
    cout << "! " << x << endl;
}

void solve()
{

    int l = 1, r = 1e6;
    int res = -1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        ask(m);
        string s;
        cin >> s;
        if (s == "<")
        {
            r = m - 1;
        }
        else
        {
            res = m;
            l = m + 1;
        }
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