#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> billetes = {100, 20, 10, 5, 1};

    cin >> n;

    int respuesta = 0;

    for (int i = 0; i < billetes.size(); i++)
    {
        respuesta += n / billetes[i];
        n = n % billetes[i];
    }

    cout << respuesta << endl;
}