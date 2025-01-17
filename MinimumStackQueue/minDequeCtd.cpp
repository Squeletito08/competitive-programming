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

template <typename T>
class MinDequeCtd
{
private:
    std::deque<pair<T, T>> dq_ctd;
    int cnt_added = 0;
    int cnt_removed = 0;

public:
    T min()
    {
        return dq_ctd.front().fi;
    }

    void push_back(T x)
    {
        while (!dq_ctd.empty() && dq_ctd.back().fi > x)
            dq_ctd.pop_back();

        dq_ctd.push_back({x, cnt_added});
        cnt_added++;
    }

    void pop_front()
    {
        if (!dq_ctd.empty() && dq_ctd.front().se == cnt_removed)
            dq_ctd.pop_front();
        cnt_removed++;
    }

    void print()
    {
        for (auto p : dq_ctd)
            cout << "(" << p.fi << ", " << p.se << ") ";
    }
};

template <typename T>
class PrintMinDequeCtd
{
private:
    MinDequeCtd<T> dq;
    vector<T> v;
    int n;
    int k;

public:
    PrintMinDequeCtd(std::vector<T> &inputVec, int size, int windowSize)
        : v(inputVec), n(size), k(windowSize) {}

    void window_number(int i)
    {
        cout << "Ventana " << i << ": ";
        for (int j = i; j < i + k; j++)
            cout << v[j] << " ";
        cout << endl;
    }

    void print_min_deque_info()
    {
        cout << "MinDequeCtd: ";
        dq.print();
        cout << endl;
        cout << "min -> " << dq.min() << endl;
    }

    void resolution_min_deque_ctd()
    {

        cout << "\n\n----------Con double-ended queue con contadores----------" << endl;

        window_number(0);

        int i = 0;
        for (; i < k; i++)
        {
            dq.push_back(v[i]);
        }

        print_min_deque_info();
        cout << endl;

        for (; i < n; i++)
        {
            window_number(i - k + 1);
            cout << "se trata de agregar: " << v[i] << endl;
            cout << "se trata de eliminar el índice: " << (i - k) << endl;
            dq.pop_front();
            dq.push_back(v[i]);
            print_min_deque_info();
            cout << endl;
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi nums(n);
    read_vi(nums, n);

    PrintMinDequeCtd<int> print_dq_ctd(nums, n, k);

    print_dq_ctd.resolution_min_deque_ctd();
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
