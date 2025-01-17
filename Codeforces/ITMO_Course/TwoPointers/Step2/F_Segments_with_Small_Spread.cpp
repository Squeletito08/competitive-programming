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
class MyStack
{

private:
    stack<T> s, s_min, s_max;

public:
    void push(T x)
    {
        s.push(x);
        if (s_min.empty())
            s_min.push(x);
        else
            s_min.push(::min(x, s_min.top()));

        if (s_max.empty())
            s_max.push(x);
        else
            s_max.push(::max(x, s_max.top()));
    }

    T pop()
    {
        T x = s.top();
        s.pop();
        s_min.pop();
        s_max.pop();
        return x;
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

    void print_stack()
    {
        stack<T> temp = s;
        cout << "[ ";
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "]";
    }
};

template <typename T>
class QueueWithStacks
{
private:
    MyStack<T> s1, s2;

public:
    T min()
    {
        if (s1.empty())
            return s2.min();
        if (s2.empty())
            return s1.min();
        return ::min(s1.min(), s2.min());
    }

    T max()
    {
        if (s1.empty())
            return s2.max();
        if (s2.empty())
            return s1.max();
        return ::max(s1.max(), s2.max());
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

    void print_queues()
    {
        cout << "Stack s1: ";
        s1.print_stack();
        cout << ", Stack s2: ";
        s2.print_stack();
        cout << endl;
    }
};

bool good(QueueWithStacks<ll> &cola, ll k)
{
    return cola.max() - cola.min() <= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll nums(n);
    read_vll(nums, n);

    int l = 0;
    ll res = 0;

    QueueWithStacks<ll> cola;

    for (int r = 0; r < n; r++)
    {
        cola.push(nums[r]);

        while (!good(cola, k))
        {
            cola.pop();
            l++;
        }

        res += r - l + 1;
    }

    cout << res << endl;
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