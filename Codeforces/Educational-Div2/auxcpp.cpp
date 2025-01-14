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

// Función para calcular factorial con límite
ll factorial_limitado(ll x, ll limite)
{
    ll resultado = 1;
    for (ll i = 2; i <= x; i++)
    {
        if (resultado > limite / i)
        { // Evitar overflow
            return -1;
        }
        resultado *= i;
    }
    return resultado;
}

void solve()
{
    ll n;
    cin >> n;
    ll d;
    cin >> d;

    // Limitar el cálculo del factorial
    ll fact = factorial_limitado(n, 1e6); // Limitar tamaño del factorial
    if (fact == -1)
    {
        cout << "Factorial demasiado grande para manejar." << endl;
        return;
    }

    // Construcción segura de la cadena
    string s(fact, char('0' + d)); // Crea una cadena con `fact` repeticiones de `d`

    // Intentar convertir a número si es posible
    ll numero;
    try
    {
        numero = stoll(s);
    }
    catch (const out_of_range &)
    {
        cout << "El número generado es demasiado grande." << endl;
        return;
    }

    // Verificar divisibilidad
    vll div = {1, 3, 5, 7, 9};
    cout << "Al numero -> " << numero << " lo dividen: ";

    for (auto x : div)
    {
        if (numero % x == 0)
        {
            cout << x << " ";
        }
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
