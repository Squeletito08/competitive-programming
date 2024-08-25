#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;
        int x;
        for (int i = 0; i < n; i++)
            cin >> x;

        int posibilidades = 10 - n;
        int caso_base = 6;
        int combinaciones = factorial(posibilidades) / (2 * factorial(posibilidades - 2));
        cout << caso_base * combinaciones << endl;
    }
}