#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grafo(n + 1);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        unordered_map<int, int> adyacencias;

        for (int i = 1; i <= n; i++)
            adyacencias[grafo[i].size()]++;

        int x, y;

        for (int i = 1; i <= n; i++)
        {
            if (grafo[i].size() == 1)
            {
                int vecino = grafo[i][0];
                y = grafo[vecino].size() - 1;
                break;
            }
        }

        int no_nodo_ady1 = adyacencias[1];

        x = no_nodo_ady1 / y;

        cout << x << " " << y << endl;
    }
}