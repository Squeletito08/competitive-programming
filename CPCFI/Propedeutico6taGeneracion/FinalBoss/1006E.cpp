#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> recorrido;
vector<int> posiciones;
vector<int> long_recorrido;
int i;

int dfs(int policia)
{
    recorrido.push_back(policia);
    posiciones[policia] = i;
    i++;

    if (grafo[policia].size() == 0)
        return 0;

    int suma = grafo[policia].size();

    for (auto v : grafo[policia])
        suma += dfs(v);

    long_recorrido[policia] = suma;
    return suma;
}

int main()
{
    int n, q;
    cin >> n >> q;

    grafo.assign(n + 1, vector<int>());

    for (int i = 2; i < n + 1; i++)
    {
        int superior;
        cin >> superior;
        grafo[superior].push_back(i);
    }

    long_recorrido.assign(n + 1, 0);
    posiciones.assign(n + 1, 0);
    i = 0;
    dfs(1);

    while (q--)
    {
        int u, k;
        cin >> u >> k;

        if (long_recorrido[u] + 1 < k)
            cout << -1;
        else
            cout << recorrido[posiciones[u] + k - 1];

        cout << endl;
    }
}