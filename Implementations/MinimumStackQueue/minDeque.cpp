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
class MinDeque
{
private:
    std::deque<T> dq;

public:
    T min()
    {
        return dq.front();
    }

    void push_back(T x)
    {
        while (!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }

    void pop_front(T x)
    {
        if (!dq.empty() && dq.front() == x)
            dq.pop_front();
    }

    void print()
    {
        for (auto x : dq)
            cout << x << " ";
    }
};

template <typename T>
class PrintMinDeque
{
private:
    MinDeque<T> dq;
    vector<T> v;
    int n;
    int k;

public:
    PrintMinDeque(std::vector<T> &inputVec, int size, int windowSize)
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
        cout << "MinDeque: ";
        dq.print();
        cout << endl;
        cout << "min -> " << dq.min() << endl;
    }

    void resolution_min_deque()
    {
        cout << "\n\n----------Con double-ended queue----------" << endl;

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
            cout << "se trata de eliminar: " << v[i - k] << endl;
            dq.pop_front(v[i - k]);
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

    PrintMinDeque<int> print_dq(nums, n, k);

    print_dq.resolution_min_deque();
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