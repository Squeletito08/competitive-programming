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
const int INF = INT_MAX;

bool distintos(int n1, int n2, int i, int j)
{
    return (i >= 0 && i < n1 && j >= n1 + 1 && j < n2) || (j >= 0 && j < n1 && i >= n1 + 1 && i < n2);
}

void countingSort(vi &SA, vi &eq)
{
    int n = sz(eq);

    vi count(n);

    for (int i = 0; i < n; i++)
        count[eq[i]]++;

    for (int i = 1; i < n; i++)
        count[i] += count[i - 1];

    vi out(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int val = eq[SA[i]];
        out[count[val] - 1] = SA[i];
        count[val]--;
    }

    SA = out;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    string s = a + "$" + b + "#";

    int n1 = sz(a);
    int n2 = sz(b);
    int n = sz(s);

    vector<pair<char, int>> aux(n);

    for (int i = 0; i < n; i++)
        aux[i] = {s[i], i};

    vi SA(n);
    vi eq(n);

    sort(all(aux));

    for (int i = 0; i < n; i++)
        SA[i] = aux[i].se;

    eq[SA[0]] = 0;
    for (int i = 1; i < n; i++)
        eq[SA[i]] = (aux[i - 1].fi != aux[i].fi) ? eq[SA[i - 1]] + 1 : eq[SA[i - 1]];

    for (int h = 0; (1 << h) < n; h++)
    {
        int k = (1 << h);

        for (int i = 0; i < n; i++)
            SA[i] = (SA[i] - k + n) % n;

        countingSort(SA, eq);

        vi aux(n);

        aux[SA[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            pii ant = {eq[SA[i - 1]], eq[(SA[i - 1] + k) % n]};
            pii act = {eq[SA[i]], eq[(SA[i] + k) % n]};

            aux[SA[i]] = (act != ant) ? aux[SA[i - 1]] + 1 : aux[SA[i - 1]];
        }

        eq = aux;
    }

    vi LCP(n);

    int k = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int j = SA[eq[i] - 1];

        while (s[i + k] == s[j + k])
            k++;

        LCP[i] = k;

        k = max(k - 1, 0);
    }

    int res = 0;
    int maximo = -INF;
    for (int i = 1; i < n; i++)
    {
        if (distintos(n1, n, SA[i], SA[i - 1]))
        {
            if (LCP[SA[i]] > maximo)
            {
                maximo = LCP[SA[i]];
                res = SA[i];
            }
        }
    }

    cout << s.substr(res, LCP[res]) << endl;
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