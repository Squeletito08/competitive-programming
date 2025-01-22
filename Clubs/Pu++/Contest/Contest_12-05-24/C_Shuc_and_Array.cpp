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
    vll nums(n);
    read_vll(nums, n);

    ll res = nums[0];
    ll suma = 0;

    int act = (nums[0] % 2 == 0 ? 0 : 1);
    int ant = !act;

    for (int i = 0; i < n; i++)
    {

        act = (nums[i] % 2 == 0 ? 0 : 1);

        if (ant != act)
        {
            suma += nums[i];
        }
        else
        {
            suma = nums[i];
        }

        res = max(res, suma);
        ant = (nums[i] % 2 == 0 ? 0 : 1);

        suma = max(suma, (ll)0);
    }

    cout << res << endl;
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