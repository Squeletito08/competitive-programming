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
    string s;
    cin >> s;

    set<char> conj(all(s));

    if (conj.size() == 4 || conj.size() == 3)
    {
        cout << 4 << endl;
        return;
    }

    if (conj.size() == 2)
    {
        map<char, int> mapa;

        for (int i = 0; i < sz(s); i++)
        {
            mapa[s[i]]++;
        }

        auto it = mapa.begin();

        if (it->se == 1 || it->se == 3)
            cout << 6 << endl;
        else
            cout << 4 << endl;
        return;
    }

    cout << -1 << endl;
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