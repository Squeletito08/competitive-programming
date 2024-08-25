#include <bits/stdc++.h>
using namespace std;

vector<int> grafo;

int badge(int comienzo, int n)
{
    vector<bool> visitado(n);
    queue<int> cola;
    cola.push(comienzo);

    while (!cola.empty())
    {
        int u = cola.front();
        cola.pop();

        if (visitado[u])
            return u + 1;

        visitado[u] = 1;
        cola.push(grafo[u]);
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    grafo.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        grafo[i] = x - 1;
    }

    for (int i = 0; i < n; i++)
        cout << badge(i, n) << " ";

    cout << endl;
}