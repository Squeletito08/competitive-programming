#include <bits/stdc++.h>
using namespace std;

#define owo                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
typedef long long ll;

const int MAXN = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int r;
int identidad[2][2];
int st[4 * MAXN][2][2];

void imprime_mtz(int mtz[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mtz[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int res_mult(int A[2][2], int B[2][2], int i, int j)
{
    int res = 0;

    for (int k = 0; k < 2; k++)
    {
        res += (A[i][k] * B[k][j]) % r;
        res = res % r;
    }

    return res;
}

void merge(int A[2][2], int B[2][2], int result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = res_mult(A, B, i, j);
        }
    }
}

void build(int v, int tl, int tr, int matrices[MAXN][2][2])
{
    if (tl == tr)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                st[v][i][j] = matrices[tl][i][j];
            }
        }
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, matrices);
    build(v * 2 + 1, tm + 1, tr, matrices);

    merge(st[v * 2], st[v * 2 + 1], st[v]);
}

void query(int v, int tl, int tr, int l, int r, int result[2][2])
{
    if (tl >= l && tr <= r)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = st[v][i][j];
            }
        }
        return;
    }

    if (tl > r || tr < l)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i][j] = identidad[i][j];
            }
        }
        return;
    }

    int tm = (tl + tr) / 2;
    int left_result[2][2], right_result[2][2];
    query(v * 2, tl, tm, l, r, left_result);
    query(v * 2 + 1, tm + 1, tr, l, r, right_result);
    merge(left_result, right_result, result);
}

void solve()
{
    int n, m;
    cin >> r >> n >> m;

    int matrices[MAXN][2][2];
    identidad[0][0] = 1;
    identidad[0][1] = 0;
    identidad[1][0] = 0;
    identidad[1][1] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                cin >> matrices[i][a][b];
            }
        }
    }

    build(1, 0, n - 1, matrices);

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        int result[2][2];
        query(1, 0, n - 1, l - 1, r - 1, result);

        imprime_mtz(result);
    }
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
