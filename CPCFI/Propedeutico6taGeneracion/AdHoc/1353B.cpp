#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        int suma = 0;

        for (int i = 0; i < n; i++)
            suma += a[i];

        int i = 0;
        int contador = 0;
        while (i < n && contador < k)
        {
            if (suma - a[i] + b[i] > suma)
            {
                suma = suma - a[i] + b[i];
                contador++;
            }
            i++;
        }

        cout << suma << endl;
    }
}