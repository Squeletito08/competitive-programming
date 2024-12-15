#include <bits/stdc++.h>
using namespace std;

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

vi a = {1, -1, 0, 0};
vi b = {0, 0, 1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    char c;
    cin >> c;

    vector<vector<char>> mtz(n + 2, vector<char>(m + 2, '.'));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mtz[i][j];

    set<char> conjt;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            for (int k = 0; k < 4; k++)
            {
                if (mtz[i][j] == c && mtz[i + a[k]][j + b[k]] != '.' && mtz[i + a[k]][j + b[k]] != c)
                {
                    conjt.insert(mtz[i + a[k]][j + b[k]]);
                }
            }
        }
    }

    cout << conjt.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}