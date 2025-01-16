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

int n, m;
bool good(int i, int j)
{
    return i < n && j < m;
}

void solve()
{
    cin >> n >> m;

    vi a(n);
    vi b(m);
    read_vi(a, n);
    read_vi(b, m);

    int i = 0;
    int j = 0;
    ll k = 0;
    ll sum = 0;
    while (good(i, j))
    {
        k = 0;
        while (good(i, j) && a[i] < b[j])
            i++;
        while (good(i, j) && b[j] < a[i])
            j++;

        while (good(i, j) && a[i] == b[j])
        {
            k++;
            i++;
        }

        while (good(i, j) && b[j] == a[i - 1])
        {
            j++;
            sum += k;
        }
    }

    while (j < m && b[j] == a[n - 1])
    {
        sum += k;
        j++;
    }

    cout << sum << endl;
}

void solve2()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> a;
    vi b(m);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    ll sum = 0;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        sum += a[x];
    }

    cout << sum << endl;
}

int main()
{
    owo

        int tt = 1;

    while (tt--)
    {
        solve2();
    }

    return 0;
}