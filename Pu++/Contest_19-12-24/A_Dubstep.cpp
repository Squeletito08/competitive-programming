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

void solve()
{
    string s;
    cin >> s;
    int n = size(s);

    string res = "";

    for (int i = 0; i < n; i++)
    {
        string sig = s.substr(i, 3);

        if (sig == "WUB")
        {
            i += 2;
            continue;
        }
        else
        {
            while (sig != "WUB" && i < n)
            {
                res += s[i];
                i++;
                sig = s.substr(i, 3);
            }
            res += " ";
            i--;
        }
    }

    if (res == "")
    {
        res = "WUB";
    }

    cout << res << endl;
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