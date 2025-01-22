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

const ll MOD = 1e9 + 7;

map<ll, vector<ll>>::iterator agrega(priority_queue<ll> &poderes,
                                     map<ll, vector<ll>>::iterator it,
                                     map<ll, vector<ll>> &pwr,
                                     ll limite)
{
    while (it != pwr.end() && it->first < limite)
    {
        for (auto p : it->second)
        {
            poderes.push(p);
        }
        ++it;
    }
    return it;
}

void solve()
{
    ll n, m, l;
    cin >> n >> m >> l;

    vector<pair<ll, ll>> obst(n);

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        obst[i] = {a, b};
    }

    map<ll, vector<ll>> pwr;

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        pwr[a].pb(b);
    }

    ll poder = 1;
    ll ctd = 0;

    priority_queue<ll> poderes;
    auto indice = pwr.begin();

    for (ll i = 0; i < n; i++)
    {
        indice = agrega(poderes, indice, pwr, obst[i].f);

        if (poder + obst[i].f - 1 > obst[i].s)
        {
            continue;
        }

        while (!poderes.empty() && poder + obst[i].f - 1 <= obst[i].s)
        {
            poder += poderes.top();
            poderes.pop();
            ctd++;
        }

        if (poder + obst[i].f - 1 <= obst[i].s)
        {
            cout << -1 << endl;
            return;
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
