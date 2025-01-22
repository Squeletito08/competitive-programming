#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> izquierda(n);
        vector<int> derecha(m);

        for (int i = 0; i < n; i++)
            cin >> izquierda[i];

        for (int i = 0; i < m; i++)
            cin >> derecha[i];

        int numFormas = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (izquierda[i] + derecha[j] <= k)
                    numFormas++;

        cout << numFormas << endl;
    }
}