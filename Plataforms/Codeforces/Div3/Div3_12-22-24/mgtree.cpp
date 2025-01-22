#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;
typedef long long ll;

const ll MAX = 3e4 + 10;

vector<ll> st[MAX * 4];
ll a[MAX];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v] = {a[tl]};
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        merge(st[v * 2].begin(), st[v * 2].end(), st[v * 2 + 1].begin(), st[v * 2 + 1].end(), back_inserter(st[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int val)
{
    if (l <= tl && tr <= r)
        return st[v].end() - upper_bound(st[v].begin(), st[v].end(), val);
    if (tl > r || tr < l)
        return 0;
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, r, val) + query(v * 2 + 1, tm + 1, tr, l, r, val);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    build(1, 1, n);
    int last = 0;
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l ^= last;
        r ^= last;
        k ^= last;
        last = query(1, 1, n, l, r, k);
        cout << last << '\n';
    }

    return 0;
}