#include <bits/stdc++.h>
using namespace std;

long long int numero_substrings(long long int longitud)
{
    return (longitud * (longitud + 1)) / 2;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string cadena;
    cin >> cadena;

    unordered_set<char> conjunto;

    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        conjunto.insert(c);
    }

    long long int respuesta = 0;
    long long int longitud = 0;
    for (int i = 0; i < n; i++)
    {
        if (conjunto.count(cadena[i]))
        {
            longitud++;
        }
        else
        {
            respuesta += numero_substrings(longitud);
            longitud = 0;
        }
    }

    respuesta += numero_substrings(longitud);

    cout << respuesta << endl;
}