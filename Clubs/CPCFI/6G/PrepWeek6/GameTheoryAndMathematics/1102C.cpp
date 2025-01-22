#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> puertas(n);
    for (int i = 0; i < n; i++)
        cin >> puertas[i];

    int contador = 0;
    if (x > y)
    {
        contador = n;
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (puertas[i] <= x)
                contador++;

        if (contador % 2 == 0)
            contador = contador / 2;
        else
            contador = (contador / 2) + 1;
    }

    cout << contador << endl;
}