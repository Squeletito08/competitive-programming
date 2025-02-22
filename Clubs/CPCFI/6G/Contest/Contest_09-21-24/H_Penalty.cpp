#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define fi first
#define se second
#define sz(a) int(a.size())
#define endl "\n"
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int tc;

#define error(args...)                                \
    {                                                 \
        cerr << "--- Debug tc=" << tc << " ---" endl; \
        string _s = #args;                            \
        replace(_s.begin(), _s.end(), ',', ' ');      \
        stringstream _ss(_s);                         \
        istream_iterator<string> _it(_ss);            \
        err(_it, args);                               \
        cerr << endl;                                 \
    }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

template <typename T>
void read_v(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

constexpr ll INF_LL = LONG_LONG_MAX;
constexpr int INF_INT = INT_MAX;
constexpr int MOD = 1e9 + 7;

int turno(string &s)
{
    int g1 = 0;
    int g2 = 0;
    int an1 = 0;
    int an2 = 0;

    int i = 0;
    for (; i < sz(s); i++)
    {
        if (i % 2 == 0)
            an1++;
        else
            an2++;

        if (i % 2 == 0 && s[i] == '1')
            g1++;

        if (i % 2 != 0 && s[i] == '1')
            g2++;

        if (g1 + 5 - an1 < g2 || g2 + 5 - an2 < g1)
            return i + 1;
    }

    return i;
}

void solve()
{
    string s1 = "", s2 = "";

    for (int i = 0; i < 10; i++)
    {
        char c;
        cin >> c;

        s1 += c;
        s2 += c;

        if (c == '?')
        {
            s1[i] = (i % 2 == 0 ? '1' : '0');
            s2[i] = (i % 2 != 0 ? '1' : '0');
        }
    }

    cout << min(turno(s1), turno(s2)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (tc = 1; tc <= t; tc++)
        solve();

    return 0;
}