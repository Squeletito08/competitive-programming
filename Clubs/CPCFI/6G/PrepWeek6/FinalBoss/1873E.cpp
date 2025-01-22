#include <bits/stdc++.h>
using namespace std;

int get_siguiente(vector<int> &alturas, int anterior)
{
    for (int i = 0; i < alturas.size(); i++)
        if (alturas[i] > anterior)
            return alturas[i];

    return anterior;
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        int x;
        cin >> n >> x;
        vector<int> alturas(n);

        for (int i = 0; i < n; i++)
            cin >> alturas[i];

        sort(alturas.begin(), alturas.end());

        unordered_map<int, int> cantidad;

        for (int i = 0; i < n; i++)
            cantidad[alturas[i]]++;

        int anterior = alturas[0];
        int siguiente = get_siguiente(alturas, anterior);

        int h = alturas[0];
        int diferencia = 1;
        while (diferencia != 0)
        {
            diferencia = siguiente - anterior;

            int cantidad_niveles = x / cantidad[anterior];
            if (cantidad_niveles > diferencia && diferencia != 0)
            {
                x -= diferencia * cantidad[anterior];
                h += diferencia;
            }
            else
            {
                h += cantidad_niveles;
                break;
            }

            cantidad[siguiente] += cantidad[anterior];
            anterior = siguiente;
            siguiente = get_siguiente(alturas, anterior);
        }

        cout << h << endl;
    }
}