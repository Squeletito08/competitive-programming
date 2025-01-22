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
    string receta;
    cin >> receta;

    map<char, ll> ingredientes;

    ll a, b, c;
    cin >> a >> b >> c;
    ingredientes['B'] = a;
    ingredientes['S'] = b;
    ingredientes['C'] = c;

    map<char, ll> precios;
    cin >> a >> b >> c;
    precios['B'] = a;
    precios['S'] = b;
    precios['C'] = c;

    ll dinero;
    cin >> dinero;

    map<char, ll> necesario;

    for (int i = 0; i < sz(receta); i++)
    {
        necesario[receta[i]]++;
    }

    // tuple<ll, ll, ll, ll> = <cuantasPuedoHacer, ingredientesSobrantes, cuantoCuestaHacerUnaSinConsiderarSobrante, cuandoCuestaHacerUnaConsiderandoSobrante>
    vector<tuple<ll, ll, ll, ll>> numeroHamburguesas;

    for (auto &[key, value] : ingredientes)
    {

        if (!necesario.count(key))
        {
            continue;
        }

        ll cuantas = value / necesario[key];
        ll sobrante = value % necesario[key];
        ll sinSobrante = necesario[key] * precios[key];
        ll conSobrante = (necesario[key] - sobrante) * precios[key];
        numeroHamburguesas.pb({cuantas, sobrante, sinSobrante, conSobrante});
    }

    sort(all(numeroHamburguesas));

    ll sinIngredienteSobrante = get<2>(numeroHamburguesas[0]);
    ll conIngredienteSobrante = get<3>(numeroHamburguesas[0]);

    ll cuantasLlevamos = get<0>(numeroHamburguesas[0]);

    ll total = cuantasLlevamos;

    for (int i = 1; i < sz(numeroHamburguesas); i++)
    {

        if (cuantasLlevamos != get<0>(numeroHamburguesas[i]))
        {

            if (conIngredienteSobrante <= dinero)
            {
                dinero -= conIngredienteSobrante;
                total++;
                cuantasLlevamos++;
            }

            ll faltantes = get<0>(numeroHamburguesas[i]) - cuantasLlevamos;

            ll sePuedenHacer = min(faltantes, (sinIngredienteSobrante == 0) ? 0 : dinero / sinIngredienteSobrante);
            total += sePuedenHacer;
            dinero -= sePuedenHacer * sinIngredienteSobrante;

            cuantasLlevamos += sePuedenHacer;

            conIngredienteSobrante = sinIngredienteSobrante;
        }

        conIngredienteSobrante += get<3>(numeroHamburguesas[i]);
        sinIngredienteSobrante += get<2>(numeroHamburguesas[i]);
    }

    if (conIngredienteSobrante <= dinero)
    {
        dinero -= conIngredienteSobrante;
        total++;
    }

    total += (sinIngredienteSobrante == 0) ? 0 : dinero / sinIngredienteSobrante;

    cout << total << endl;
}

bool good(ll numero, vector<tuple<ll, ll, ll, ll>> &numeroHamburguesas, ll dinero)
{

    for (int i = 0; i < sz(numeroHamburguesas); i++)
    {

        ll cuantas = get<0>(numeroHamburguesas[i]);

        if (cuantas < numero)
        {
            if (get<3>(numeroHamburguesas[i]) <= dinero)
            {
                cuantas++;
                dinero -= get<3>(numeroHamburguesas[i]);
            }

            if (cuantas < numero)
            {
                dinero -= (numero - cuantas) * get<2>(numeroHamburguesas[i]);
            }
        }
    }

    return dinero >= 0;
}

void solveWithBinary()
{
    string receta;
    cin >> receta;

    map<char, ll> ingredientes;

    ll a, b, c;
    cin >> a >> b >> c;
    ingredientes['B'] = a;
    ingredientes['S'] = b;
    ingredientes['C'] = c;

    map<char, ll> precios;
    cin >> a >> b >> c;
    precios['B'] = a;
    precios['S'] = b;
    precios['C'] = c;

    ll dinero;
    cin >> dinero;

    map<char, ll> necesario;

    for (int i = 0; i < sz(receta); i++)
    {
        necesario[receta[i]]++;
    }

    // tuple<ll, ll, ll, ll> = <cuantasPuedoHacer, ingredientesSobrantes, cuantoCuestaHacerUnaSinConsiderarSobrante, cuandoCuestaHacerUnaConsiderandoSobrante>
    vector<tuple<ll, ll, ll, ll>> numeroHamburguesas;

    for (auto &[key, value] : ingredientes)
    {

        if (!necesario.count(key))
        {
            continue;
        }

        ll cuantas = value / necesario[key];
        ll sobrante = value % necesario[key];
        ll sinSobrante = necesario[key] * precios[key];
        ll conSobrante = (necesario[key] - sobrante) * precios[key];
        numeroHamburguesas.pb({cuantas, sobrante, sinSobrante, conSobrante});
    }

    sort(all(numeroHamburguesas));

    ll l = 0;
    ll r = 1e13;

    ll res = 0;

    while (l <= r)
    {
        ll m = l + (r - l) / 2;

        if (good(m, numeroHamburguesas, dinero))
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << res << endl;
}

int main()
{
    owo

        int tt = 1;

    while (tt--)
    {
        solveWithBinary();
    }

    return 0;
}