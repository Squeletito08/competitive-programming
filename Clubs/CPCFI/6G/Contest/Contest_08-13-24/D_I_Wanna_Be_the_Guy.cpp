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
    int n;
    cin >> n;

    set<int> niveles;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        niveles.insert(x);
    }

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        niveles.insert(x);
    }

    cout << (niveles.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    return 0;
}