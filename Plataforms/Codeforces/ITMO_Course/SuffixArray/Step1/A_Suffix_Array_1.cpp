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

void imprimeCadenas(vector<pair<pii, int>> &cadenas)
{

    for (int i = 0; i < sz(cadenas); i++)
    {
        cout << cadenas[i].fi.fi << " " << cadenas[i].fi.se << endl;
    }
    cout << endl;
}

int getValor(vector<pair<pii, int>> &cadenas, int pos, int i)
{
    if (pos == 0)
        return cadenas[i].fi.fi;

    return cadenas[i].fi.se;
}

void countingSort(vector<pair<pii, int>> &cadenas, int maximo, int pos)
{
    vector<int> count(maximo, 0);

    for (int i = 0; i < sz(cadenas); i++)
        count[getValor(cadenas, pos, i)]++;

    for (int i = 1; i < maximo; i++)
        count[i] += count[i - 1];

    vector<pair<pii, int>> output(sz(cadenas));

    for (int i = sz(cadenas) - 1; i >= 0; i--)
    {
        int val = getValor(cadenas, pos, i);
        output[count[val] - 1] = cadenas[i];
        count[val]--;
    }

    cadenas = output;
}

void radixSort(vector<pair<pii, int>> &cadenas, int maximo)
{
    countingSort(cadenas, maximo, 1);
    countingSort(cadenas, maximo, 0);
}

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = sz(s);

    vector<pair<char, int>> pos(n);
    map<int, int> equivalencias;

    for (int i = 0; i < n; i++)
    {
        pos[i] = {s[i], i};
    }

    sort(all(pos));

    int clase = 0;
    equivalencias[pos[0].se] = 0;

    for (int i = 1; i < n; i++)
    {
        if (pos[i - 1].fi != pos[i].fi)
        {
            clase++;
        }
        equivalencias[pos[i].se] = clase;
    }

    int iteraciones = log2(n) + 1;

    vector<pair<pii, int>> cadenas(n);
    for (int i = 0; i < iteraciones; i++)
    {

        for (int j = 0; j < n; j++)
        {
            int a = j;
            int b = (j + (1 << i)) % n;
            cadenas[j] = {{equivalencias[a], equivalencias[b]}, j};
        }

        // radixSort(cadenas, n);
        sort(all(cadenas));

        int clase = 0;
        equivalencias[cadenas[0].se] = 0;

        for (int j = 1; j < n; j++)
        {
            if (cadenas[j - 1].fi != cadenas[j].fi)
            {
                clase++;
            }
            equivalencias[cadenas[j].se] = clase;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << cadenas[i].se << " ";
    }
    cout << endl;
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