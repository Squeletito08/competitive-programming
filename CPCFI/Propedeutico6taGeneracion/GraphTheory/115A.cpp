#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;

int longitud_rama(int v)
{
    if (grafo[v][0] == -1)
        return 1;

    return 1 + longitud_rama(grafo[v][0]);
}

int main()
{
    int n;
    cin >> n;

    grafo.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        grafo[i].push_back(v);
    }

    int maximo = 0;

    for (int i = 1; i <= n; i++)
        maximo = max(maximo, longitud_rama(i));

    cout << maximo << endl;
}