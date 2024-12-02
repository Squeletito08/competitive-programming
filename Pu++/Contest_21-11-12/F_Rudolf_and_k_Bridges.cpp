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
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vll> river(n, vll(m));

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> river[i][j];

    vector<ll> puentes(n);

    for (ll i = 0; i < n; i++)
    {
        deque<pair<ll, ll>> dq;
        ll suma = 0;
        ll j = 1;
        for (; j <= d + 1; j++)
        {
            suma = river[i][j] + 2;
            while (!dq.empty() && suma <= dq.back().second)
                dq.pop_back();
            dq.push_back({j, suma});
        }

        for (; j < m - 1; j++)
        {
            suma = river[i][j] + 1 + dq.front().second;

            while (!dq.empty() && dq.front().first <= j - d - 1)
                dq.pop_front();

            while (!dq.empty() && suma <= dq.back().second)
                dq.pop_back();
            dq.push_back({j, suma});
        }

        puentes[i] = dq.front().second + 1;
    }

    for (ll i = 0; i < n; i++)
        if (d == m || d + 1 == m || d == m - 2)
            puentes[i] = 2;

    ll suma = 0;
    for (ll i = 0; i < k; i++)
        suma += puentes[i];

    ll minimo = suma;
    ll i = 0;
    ll j = k;
    while (j <= puentes.size() - 1)
    {
        suma = suma - puentes[i] + puentes[j];
        if (suma < minimo)
            minimo = suma;
        i++;
        j++;
    }

    cout << minimo << endl;
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