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
        string problemas;
        cin >> problemas;
        int res = n;
        unordered_set<char> conjunto;
        for (int i = 0; i < n; i++)
        {
            if (conjunto.count(problemas[i]) == 0)
            {
                conjunto.insert(problemas[i]);
                res++;
            }
        }
        cout << res << endl;
    }
}
