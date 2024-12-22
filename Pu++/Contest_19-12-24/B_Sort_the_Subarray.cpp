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

void arreglos_iguales(vi &A, vi &B, int n)
{

    int ind_i = 0;
    int ind_j = 0;

    int i = 0, j = 0;

    int ant = B[0];
    bool ord = false;

    for (int k = 1; k < n; k++)
    {

        if (j - i > ind_j - ind_i)
        {
            ind_i = i;
            ind_j = j;
        }
        if (B[k] >= ant && !ord)
        {
            i = k - 1;
            ord = true;
            j = k;
        }

        if (B[k] >= ant && ord)
        {
            j = k;
        }

        if (B[k] < ant)
        {
            ord = false;
        }

        ant = B[k];
    }

    if (j - i > ind_j - ind_i)
    {
        ind_i = i;
        ind_j = j;
    }

    cout << ind_i + 1 << " " << ind_j + 1 << endl;
}

void solve()
{
    int n;
    cin >> n;

    vi A(n);
    vi B(n);

    read_vi(A, n);
    read_vi(B, n);

    bool iguales = true;

    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            iguales = false;
            break;
        }
    }

    if (iguales)
    {
        arreglos_iguales(A, B, n);
    }
    else
    {

        int inicio = -1, fin = -1;

        for (int i = 0; i < n; i++)
        {
            if (A[i] - B[i] != 0)
            {
                inicio = i;
                break;
            }
        }

        while (inicio - 1 >= 0 && B[inicio] >= B[inicio - 1])
        {
            if (B[inicio] >= B[inicio - 1])
            {
                inicio--;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] - B[i] != 0)
            {
                fin = i;
                break;
            }
        }

        while (fin + 1 < n && B[fin] <= B[fin + 1])
        {
            if (B[fin] <= B[fin + 1])
            {
                fin++;
            }
        }

        cout << inicio + 1 << " " << fin + 1 << endl;
    }
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