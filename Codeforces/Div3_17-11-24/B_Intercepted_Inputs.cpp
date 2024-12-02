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
    int k;
    cin >> k;

    int producto = k - 2;

    vi a(k);
    map<int, int> mapa;

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        mapa[x]++;
    }

    int p1, p2;

    for (int i = 0; i < k; i++)
    {
        p1 = a[i];
        p2 = producto / p1;

        if (p1 <= producto && mapa.count(p2) && (p1 != p2 || mapa[p2] >= 2) && p1 * p2 == producto)
        {

            cout << p1 << " " << p2 << endl;
            return;
        }
    }
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