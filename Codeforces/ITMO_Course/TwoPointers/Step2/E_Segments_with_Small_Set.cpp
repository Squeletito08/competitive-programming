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

int agrega(vi &aux, int x)
{
    aux[x]++;
    if (aux[x] == 1)
        return 1;
    return 0;
}

int elimina(vi &aux, int x)
{
    aux[x]--;
    if (aux[x] == 0)
        return 1;
    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi nums(n);
    read_vi(nums, n);

    vi aux(1e5 + 1);

    int l = 0;
    ll res = 0;

    int ctd = 0;
    for (int r = 0; r < n; r++)
    {

        ctd += agrega(aux, nums[r]);

        while (ctd > k)
        {
            ctd -= elimina(aux, nums[l]);
            l++;
        }

        res += r - l + 1;
    }

    cout << res << endl;
}

void solve2()
{
    int n, k;
    cin >> n >> k;

    vi nums(n);
    read_vi(nums, n);

    map<int, int> mapa;

    int l = 0;
    ll res = 0;
    ll ctd = 0;

    for (int r = 0; r < n; r++)
    {

        mapa[nums[r]]++;

        while (mapa.size() > k)
        {
            mapa[nums[l]]--;
            if (mapa[nums[l]] == 0)
                mapa.erase(nums[l]);
            l++;
        }

        res += r - l + 1;
    }

    cout << res << endl;
}
int main()
{
    owo

        int tt = 1;

    while (tt--)
    {
        // solve();
        solve2();
    }

    return 0;
}