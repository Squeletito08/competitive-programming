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

        int menor = arreglo[0];

        int j = 1;
        for (; j < n; j++)
        {
            if (arreglo[j] != menor)
                break;
        }

        cout << n - j << endl;
    }
}