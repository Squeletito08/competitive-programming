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
    string s;
    cin >> s;

    int n = sz(s);

    string res = "";

    for (int i = 0; i < n; i++)
    {
        int val = s[i] - '0';

        vector<pii> nums;

        int k = 9 - val - 1;
        k += i + 1;
        int a = 1;
        for (int j = i + 1; j < min(k, n); j++)
        {
            nums.pb({s[j] - '0' - a, j});
            a++;
        }

        sort(all(nums), [](const pii &a, const pii &b)
             {
                 if (a.first != b.first)
                     return a.first > b.first; 
                 return a.second < b.second; });

        if (nums.empty() || nums[0].fi <= val)
        {
            continue;
        }

        int indice = nums[0].se;

        char c = to_string(nums[0].fi)[0];

        s[indice] = c;

        for (int h = indice; h > i; h--)
        {
            swap(s[h], s[h - 1]);
        }
    }

    cout << s << endl;
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