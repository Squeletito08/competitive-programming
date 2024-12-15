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

void solve()
{
    int n, k;
    cin >> n >> k;

    vll nums(n);

    read_vll(nums, n);

    map<ll, ii> mapa;

    for (int i = 0; i < sz(nums); i++)
    {
        if (mapa.count(nums[i]))
        {
            mapa[nums[i]].se = i;
        }
        else
        {
            mapa[nums[i]] = {i, i};
        }
    }

    while (k--)
    {
        ll a, b;
        cin >> a >> b;

        if (!mapa.count(a) || !mapa.count(b))
        {
            cout << "NO" << endl;
            continue;
        }

        int i = mapa[a].fi;
        int j = mapa[b].se;

        if (i < j)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;

    while (tt--)
    {
        solve();
    }

    return 0;
}