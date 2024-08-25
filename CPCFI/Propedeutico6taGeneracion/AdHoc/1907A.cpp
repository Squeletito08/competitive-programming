#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        string casilla;
        cin >> casilla;

        int numero = casilla[1] - '0';

        char aux = 'a';

        for (int i = 0; i < 8; i++)
        {
            if (aux != casilla[0])
                cout << aux << casilla[1] << endl;
            aux++;
        }

        for (int i = 1; i <= 8; i++)
        {
            if (i != numero)
                cout << casilla[0] << i << endl;
        }
    }
}