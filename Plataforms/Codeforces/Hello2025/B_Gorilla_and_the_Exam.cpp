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
    int n, k;
    cin >> n >> k;

    vi nums(n);
    map<int, int> aux;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        aux[nums[i]]++;
    }

    vector<int> cant;

    for (auto x : aux)
    {
        cant.pb(x.se);
    }

    sort(all(cant));

    int j = 0;

    for (int i = 0; i < sz(cant); i++)
    {

        if (k >= cant[i])
        {
            k -= cant[i];
            j = i + 1;
        }
        else
        {
            break;
        }
    }

    if (sz(cant) == j)
    {
        cout << 1 << endl;
        return;
    }
    cout << sz(cant) - j << endl;
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