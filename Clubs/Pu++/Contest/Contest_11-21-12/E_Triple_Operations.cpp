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

int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

vll nums(2e5 + 10);
vll prefix(2e5 + 10);

void solve()
{

    ll l, r;
    cin >> l >> r;

    cout << nums[l] * 2 + prefix[r] - prefix[l] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (ll i = 1; i < 2e5 + 10; i++)
    {
        nums[i] = log_a_to_base_b(i, 3) + 1;
    }

    for (ll i = 1; i < 2e5 + 10; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    while (t--)
    {
        solve();
    }

    return 0;
}