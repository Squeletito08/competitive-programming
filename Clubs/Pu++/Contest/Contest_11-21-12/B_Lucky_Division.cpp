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

bool si(int num)
{
    string x = to_string(num);

    for (int i = 0; i < sz(x); i++)
    {
        if (x[i] != '4' && x[i] != '7')
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    if (n % 4 == 0 || n % 7 == 0)
    {
        cout << "YES" << endl;
        return;
    }

    set<int> divisores;

    for (int i = 4; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisores.insert(i);
        }
    }

    for (auto x : divisores)
    {
        if (si(x))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}