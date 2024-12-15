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

bool suma9(int ctd2, int ctd3, ll suma)
{
    for (int a = 0; a <= ctd2; a++)
    {
        for (int b = 0; b <= ctd3; b++)
        {

            if ((suma + 2 * a + 6 * b) % 9 == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;

    ll sum = 0;

    ll ctd2 = 0;
    ll ctd3 = 0;

    for (int i = 0; i < sz(s); i++)
    {
        string aux = "0";
        aux += s[i];
        sum += stoi(aux);

        if (s[i] == '3')
        {
            ctd3++;
        }

        if (s[i] == '2')
        {
            ctd2++;
        }
    }

    if (sum % 9 == 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (suma9(ctd2, ctd3, sum))
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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