#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long int> columnas(n);

    for (int i = 0; i < n; i++)
        cin >> columnas[i];

    vector<long long int> sumDer_Izq(n);
    vector<long long int> sumIzq_Der(n);

    for (int i = 0; i < n; i++)
    {
        long long int danio = 0;
        if (columnas[i] > columnas[i + 1])
            danio = columnas[i] - columnas[i + 1];

        sumDer_Izq[i + 1] = sumDer_Izq[i] + danio;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        long long int danio = 0;
        if (columnas[i] > columnas[i - 1])
            danio = columnas[i] - columnas[i - 1];

        sumIzq_Der[i - 1] = sumIzq_Der[i] + danio;
    }

    while (m--)
    {
        int s, t;
        cin >> s >> t;
        s--;
        t--;

        if (s < t)
            cout << sumDer_Izq[t] - sumDer_Izq[s];

        else
            cout << sumIzq_Der[t] - sumIzq_Der[s];

        cout << endl;
    }
}