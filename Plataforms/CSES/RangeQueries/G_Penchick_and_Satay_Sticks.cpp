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
    vi perm(n + 1);

    map<int, int> pos;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        perm[i] = x;
        pos[x] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int pos_act = pos[i];

        if (pos_act - i > 2)
        {
            cout << "NO" << endl;
            return;
        }

        while (pos[i] != i)
        {
            if (abs(i - perm[pos_act - 1]) != 1)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                swap(perm[pos_act], perm[pos_act - 1]);
                pos[i] = pos_act - 1;
                pos[perm[pos_act]] = pos_act;
                pos_act--;
            }
        }
    }

    cout << "YES" << endl;
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