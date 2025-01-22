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

int comp(string &s, string &t, int a)
{
    int j = 0;
    for (int i = a; i < sz(s) && j < sz(t); i++)
    {
        if (s[i] < t[j])
        {
            return -1;
        }
        else if (s[i] > t[j])
        {
            return 1;
        }
        j++;
    }

    if ((sz(s) - a) < sz(t))
    {
        return -1;
    }

    return 0;
}
bool binarySearch(vi &p, string &s, string &t)
{

    int l = 0;
    int r = sz(p) - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int cond = comp(s, t, p[m]);

        if (cond == 0)
        {
            return true;
        }

        if (cond == -1)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return false;
}

void countingSort(vi &p, vi &c)
{
    int m = sz(c);
    vector<int> count(m, 0);

    for (int i = 0; i < m; i++)
        count[c[i]]++;

    for (int i = 1; i < m; i++)
        count[i] += count[i - 1];

    vi output(m);

    for (int i = m - 1; i >= 0; i--)
    {
        int val = c[p[i]];
        output[count[val] - 1] = p[i];
        count[val]--;
    }

    p = output;
}

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = sz(s);
    int q;
    cin >> q;

    vector<pair<char, int>> pos(n);
    vi p(n);
    vi equivalencias(n);

    for (int i = 0; i < n; i++)
    {
        pos[i] = {s[i], i};
    }

    sort(all(pos));

    for (int i = 0; i < n; i++)
        p[i] = pos[i].se;

    int clase = 0;
    equivalencias[p[0]] = 0;

    for (int i = 1; i < n; i++)
        equivalencias[p[i]] = (pos[i - 1].fi != pos[i].fi) ? equivalencias[p[i - 1]] + 1 : equivalencias[p[i - 1]];

    int iteraciones = log2(n) + 1;

    for (int k = 0; k < iteraciones; k++)
    {

        for (int j = 0; j < n; j++)
            p[j] = (p[j] - (1 << k) + n) % n;

        countingSort(p, equivalencias);
        // sort(all(cadenas));

        vi aux(n);
        aux[p[0]] = 0;

        for (int j = 1; j < n; j++)
        {
            pii ant = {equivalencias[p[j - 1]], equivalencias[(p[j - 1] + (1 << k)) % n]};
            pii act = {equivalencias[p[j]], equivalencias[(p[j] + (1 << k)) % n]};

            aux[p[j]] = (ant != act) ? aux[p[j - 1]] + 1 : aux[p[j - 1]];
        }

        equivalencias = aux;
    }

    while (q--)
    {
        string buscar;
        cin >> buscar;

        cout << ((binarySearch(p, s, buscar)) ? "Yes" : "No");
        cout << endl;
    }
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