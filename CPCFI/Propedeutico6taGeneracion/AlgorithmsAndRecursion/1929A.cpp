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

        vector<int> arreglo(n);
        for (int i = 0; i < n; i++)
            cin >> arreglo[i];

        sort(arreglo.begin(), arreglo.end());

        int suma = 0;

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
                suma += arreglo[i + 1] - arreglo[i];
        }

        cout << suma << endl;
    }
}