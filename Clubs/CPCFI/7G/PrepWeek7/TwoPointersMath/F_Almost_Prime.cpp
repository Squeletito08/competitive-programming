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

vector<int> numeros;
void criba(int n)
{

    for (int i = 2; i < n; ++i)
    {
        if (numeros[i] == 0)
        {
            numeros[i] = 1;
            for (int h = 2; h * i < n; ++h)
                numeros[i * h]++;
        }
    }
}

void solve()
{

    int x;
    cin >> x;

    numeros.resize(3010);
    criba(3010);

    int ctd = 0;

    for (int i = 0; i <= x; i++)
    {
        if (numeros[i] == 2)
        {
            ctd++;
        }
    }

    cout << ctd << endl;
}

int main()
{
    owo

        int tt = 1;

    while (tt--)
    {
        solve();
    }

    return 0;
}