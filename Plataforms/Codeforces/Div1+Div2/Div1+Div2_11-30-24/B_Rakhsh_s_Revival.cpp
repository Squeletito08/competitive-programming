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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string st;
    cin >> st;

    int ctd = 0;

    int numCeros = 0;

    for (int i = 0; i < n; i++)
    {
        if (st[i] == '0')
        {
            numCeros++;
        }
        else
        {
            numCeros = 0;
        }

        if (numCeros == m)
        {
            ctd++;
            int j = i;
            for (; j < k + i && j < n; j++)
            {
                st[j] = '1';
            }
            i = j - 1;
            numCeros = 0;
        }
    }

    cout << ctd << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}