#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
queue<pair<int, int>> visitados;

int n, m;

bool limites(int i, int j)
{
    return (i >= 0 && i < n) && (j >= 0 && j < m);
}

void mete_vecinos(int i, int j)
{
    if (limites(i + 1, j))
        visitados.push({i + 1, j});
    if (limites(i - 1, j))
        visitados.push({i - 1, j});
    if (limites(i, j + 1))
        visitados.push({i, j + 1});
    if (limites(i, j - 1))
        visitados.push({i, j - 1});
}

int suma_camino(int i, int j)
{
    queue<pair<int, int>>().swap(visitados);

    int suma = 0;
    suma += grid[i][j];

    grid[i][j] = 0;
    mete_vecinos(i, j);

    while (!visitados.empty())
    {
        int k, l;
        k = visitados.front().first;
        l = visitados.front().second;
        visitados.pop();
        if (grid[k][l] != 0)
        {
            mete_vecinos(k, l);
            suma += grid[k][l];
            grid[k][l] = 0;
        }
    }

    return suma;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;

        grid.resize(n);
        for (int i = 0; i < n; i++)
        {
            grid[i].resize(m);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        int maximo = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    maximo = max(maximo, suma_camino(i, j));
                }
            }
        }

        cout << maximo << endl;
    }
}
