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
    string s;
    cin >> s;
    s += "$";
    int n = sz(s);

    vector<pair<char, int>> aux(n);

    for (int i = 0; i < n; i++)
        aux[i] = {s[i], i};

    sort(all(aux));

    vi SA(n);
    vi eq(n);

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

            aux[SA[i]] = (ant != act) ? aux[SA[i - 1]] + 1 : aux[SA[i - 1]];
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

    ll sum = 0;

    for (int i = 0; i < n; i++)
        sum += LCP[i];

    ll n_aux = n - 1;

    ll number_of_substrings = (n_aux * (n_aux + 1)) / 2;

    cout << number_of_substrings - sum << endl;
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