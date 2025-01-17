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
struct MyStack
{
    std::stack<T> s;
    std::stack<T> s_min;
    std::stack<T> s_max;

    void push(T x)
    {
        s.push(x);

        if (s_min.empty())
            s_min.push(x);
        else
            s_min.push(std::min(x, s_min.top()));

        if (s_max.empty())
            s_max.push(x);
        else
            s_max.push(std::max(x, s_max.top()));
    }

    T pop()
    {
        T x = s.top();
        s.pop();
        s_min.pop();
        s_max.pop();

        return x;
    }

    T top()
    {
        return s.top();
    }

    T min()
    {
        return s_min.top();
    }

    T max()
    {
        return s_max.top();
    }

    bool empty()
    {
        return s.empty();
    }
};

template <typename T>
struct MinDeque
{
    std::deque<T> q;

    T min()
    {
        return q.front();
    }

    void push_back(T x)
    {
        while (!q.empty() && q.back() > x)
            q.pop_back();
        q.push_back(x);
    }

    void pop_front(T x)
    {
        if (!q.empty() && q.front() == x)
            q.pop_front();
    }
};

template <typename T>
struct MinDequeCtd
{
    std::deque<pair<T, T>> q;

    int cnt_added = 0;
    int cnt_removed = 0;

    T min()
    {
        return q.front().fi;
    }

    void push_back(T x)
    {
        while (!q.empty() && q.back() > x)
            q.pop_back();

        q.push_back({x, cnt_added});
        cnt_added++;
    }

    void pop_front()
    {
        if (!q.empty() && q.front().se == cnt_removed)
            q.pop_front();
        cnt_removed++;
    }
};

template <typename T>
struct MyQueueWithStacks
{
    MyStack<T> s1, s2;

    T min()
    {
        T minimum;
        if (s1.empty() || s2.empty())
            minimum = s1.empty() ? s2.min() : s1.min();
        else
            minimum = ::min(s1.min(), s2.min());

        return minimum;
    }

    T max()
    {
        T maximum;
        if (s1.empty() || s2.empty())
            maximum = s1.empty() ? s2.max() : s1.max();
        else
            maximum = ::max(s1.max(), s2.max());

        return maximum;
    }

    void push(T x)
    {
        s2.push(x);
    }

    T pop()
    {
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.pop());
            }
        }
        return s1.pop();
    }
};

void window_number(int i, vi &nums, int k)
{
    cout << "Ventana " << i << ": ";
    for (int j = i; j < i + k; j++)
        cout << nums[j] << " ";
    cout << endl;
}

template <typename T>
void print_min(MinDeque<T> &q)
{
    cout << "min -> " << q.min() << endl;
}

template <typename T>
void print_MinDeque(MinDeque<T> &x)
{
    cout << "Deque: ";
    for (auto x : x.q)
        cout << x << " ";
    cout << endl;
}

template <typename T>
void resolution_MinDeque(vi &nums, int n, int k)
{
    cout << "Con double-ended queue: " << endl
         << endl;
    MinDeque<T> q;

    window_number(0, nums, k);

    int i = 0;
    for (; i < k; i++)
    {
        q.push_back(nums[i]);
    }

    print_MinDeque<T>(q);
    print_min<T>(q);
    cout << endl;

    for (; i < n; i++)
    {
        window_number(i - k + 1, nums, k);
        cout << "se trata de agregar: " << nums[i] << endl;
        cout << "se trata de eliminar: " << nums[i - k] << endl;
        q.pop_front(nums[i - k]);
        q.push_back(nums[i]);
        print_MinDeque<T>(q);
        print_min<T>(q);
        cout << endl;
    }
}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi nums(n);

    read_vi(nums, n);

    resolution_MinDeque<int>(nums, n, k);
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