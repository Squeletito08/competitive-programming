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
        string numero;
        cin >> numero;

        int paresRaze = 0;
        int imparesRaze = 0;

        int paresBrench = 0;
        int imparesBrench = 0;
        for (int i = 0; i < n; i++)
        {
            int num = numero[i] - '0';
            if (i % 2 == 0)
            {
                if (num % 2 == 0)
                    paresRaze++;
                else
                    imparesRaze++;
            }
            else
            {
                if (num % 2 == 0)
                    paresBrench++;
                else
                    imparesBrench++;
            }
        }

        int turnos = n - 1;
        bool Raze = true;
        while (turnos-- && (imparesRaze + paresRaze > 0) && (imparesBrench + paresBrench > 0))
        {

            if (Raze)
            {
                if (paresRaze > 0)
                {
                    paresRaze--;
                }
                else
                {
                    imparesRaze--;
                }
            }
            else
            {
                if (imparesBrench > 0)
                {
                    imparesBrench--;
                }
                else
                {
                    paresBrench--;
                }
            }

            Raze = !Raze;
        }

        if (imparesBrench + imparesRaze > 0)
            cout << 1;
        else
            cout << 2;

        cout << endl;
    }
}