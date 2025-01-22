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

    vi nums(n);
    read_vi(nums, n);

    set<int> visto;
    vi aux;

    for (int i = 0; i < n; i++)
    {
        if (!visto.count(nums[i]))
        {
            aux.pb(nums[i]);
            visto.insert(nums[i]);
        }
    }

    vi res;
    int k = aux.size();

    for (auto x : aux)
    {
        res.pb(x);
    }

    for (int i = 1; i <= 2e5 + 10 && res.size() != n; i++)
    {
        if (!visto.count(i))
        {
            res.pb(i);
        }
    }

    for (auto x : res)
    {
        cout << x << " ";
    }
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