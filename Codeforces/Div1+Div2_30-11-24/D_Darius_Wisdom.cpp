#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
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

void intercambia01(vi &nums, set<int> &unos, set<int> &ceros, vector<ii> &res, int i)
{
    auto indiceUno = unos.begin();

    res.pb({i, *indiceUno});
    swap(nums[i], nums[*indiceUno]);

    unos.erase(indiceUno);
    unos.insert(i);

    ceros.erase(i);
    ceros.insert(*indiceUno);
}

void intercambia21(vi &nums, set<int> &unos, set<int> &doses, vector<ii> &res, int i)
{
    auto indiceDos = doses.begin();

    res.pb({i, *indiceDos});
    swap(nums[i], nums[*indiceDos]);

    unos.erase(i);
    unos.insert(*indiceDos);

    doses.erase(*indiceDos);
    doses.insert(i);
}

void solve()
{
    int n;
    cin >> n;
    vi nums(n + 1);

    int num0 = 0;
    int num1 = 0;
    int num2 = 0;

    set<int> ceros, unos, doses;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            num1++;
            unos.insert(i);
        }

        if (x == 0)
        {
            num0++;
            ceros.insert(i);
        }

        if (x == 2)
        {
            num2++;
            doses.insert(i);
        }

        nums[i] = x;
    }

    ii interCeros = {1, num0};
    ii interUnos = {num0 + 1, num0 + num1};
    ii interDoses = {interUnos.s + 1, n};

    vector<ii> res;
    int k = 0;

    for (int i = interDoses.s; i >= interDoses.f; i--)
    {
        if (nums[i] == 1)
        {
            k++;
            intercambia21(nums, unos, doses, res, i);
        }

        if (nums[i] == 0)
        {
            k += 2;

            intercambia01(nums, unos, ceros, res, i);
            intercambia21(nums, unos, doses, res, i);
        }
    }

    for (int i = interUnos.s; i >= interUnos.f; i--)
    {
        if (nums[i] == 0)
        {
            k++;
            intercambia01(nums, unos, ceros, res, i);
        }
    }

    cout << k << endl;

    for (auto x : res)
    {
        cout << x.f << " " << x.s << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}