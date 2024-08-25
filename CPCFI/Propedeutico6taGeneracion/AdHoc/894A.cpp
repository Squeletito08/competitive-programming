#include <bits/stdc++.h>
using namespace std;

int main()
{
    string cadena;
    cin >> cadena;

    int n = cadena.length();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if ('Q' != cadena[i])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if ('A' != cadena[j])
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if ('Q' == cadena[k])
                    res++;
            }
        }
    }

    cout << res << endl;
}