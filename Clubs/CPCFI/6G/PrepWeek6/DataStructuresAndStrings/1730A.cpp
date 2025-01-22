#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> orbitas(n);
        for (int i = 0; i < n; i++)
            cin >> orbitas[i];

        unordered_map<int, int> valores;

        for (int i = 0; i < n; i++)
        {
            valores[orbitas[i]]++;
        }

        int total = 0;
        for (auto const &valor : valores)
        {
            if (valor.second > 1)
                if (c < valor.second)
                    total += c;
                else
                    total += valor.second;
            else
                total++;
        }

        cout << total << endl;
    }
}