#include <bits/stdc++.h>
using namespace std;

bool se_puede(string cadena)
{
    int numeroUnos = 0;

    for (int i = 0; i < cadena.size(); i++)
        if (cadena[i] == '1')
            numeroUnos++;

    if (numeroUnos == 2)
    {
        int primerUno;
        for (int i = 0; i < cadena.size(); i++)
            if (cadena[i] == '1')
            {
                primerUno = i;
                break;
            }

        return cadena[primerUno + 1] != '1';
    }
    return numeroUnos % 2 == 0;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string cadena;
        cin >> cadena;

        if (se_puede(cadena))
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}