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
    ll n, d;
    cin >> n >> d;

    set<int> dig;

    if (n == 2)
    {
        vi nums = {1, 3, 5, 7, 9};

        for (auto x : nums)
        {
            if (d % x == 0)
            {
                dig.insert(x);
            }
        }
    }
    else
    {

        dig.insert(1);
        dig.insert(3);
        dig.insert(7);

        if (d == 5)
        {
            dig.insert(5);
        }

        if (n >= 6 || d == 9 || d == 3 || d == 6)
        {
            dig.insert(9);
        }
    }
    for (auto x : dig)
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