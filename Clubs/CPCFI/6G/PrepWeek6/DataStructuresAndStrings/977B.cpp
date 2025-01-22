#include <bits/stdc++.h>
using namespace std;

int numero_apariciones(string &s, string &twogram)
{

    int cont = 0;
    for (int i = 0; i <= s.size() - twogram.size(); i++)
    {

        string sub = s.substr(i, twogram.size());
        if (sub == twogram)
            cont++;
    }
    return cont;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max = 0;
    string respuesta;

    for (int i = 0; i < n; i++)
    {
        if (i + 1 <= n - 1)
        {
            string twogram = s.substr(i, 2);
            int num = numero_apariciones(s, twogram);
            if (num > max)
            {
                max = num;
                respuesta = twogram;
            }
        }
    }

    cout << respuesta << endl;
}