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

    vector<vector<char>> mtz(n + 2, vector<char>(n + 2, '0'));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mtz[i][j];
        }
    }

    vi perm(n);

    vi ady(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mtz[i][j] == '1' && j > i)
            {
                ady[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int k = 0;

        int j = n - 1;
        for (; j >= 0 && k < ady[i] + 1; j--)
        {
            if (perm[j] == 0)
                k++;
        }

        perm[j + 1] = i;
    }

    for (auto x : perm)
        cout << x << " ";
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