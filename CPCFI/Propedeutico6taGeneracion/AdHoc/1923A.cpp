#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> casillas(n);

        for (int i = 0; i < n; i++)
            cin >> casillas[i];

        int primerUno;

        for (int i = 0; i < n; i++)
            if (casillas[i])
            {
                primerUno = i;
                break;
            }

        int ultimoUno;

        for (int i = n - 1; i >= 0; i--)
            if (casillas[i])
            {
                ultimoUno = i;
                break;
            }

        int respuesta = 0;

        for (int i = primerUno; i < ultimoUno; i++)
        {
            if (casillas[i] == 0)
                respuesta++;
        }

        cout << respuesta << endl;
    }
}