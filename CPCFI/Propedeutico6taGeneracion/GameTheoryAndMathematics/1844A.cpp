#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int a, b;
        cin >> a >> b;

        if (a > 1)
            cout << 1;
        else if (b == 2)
            cout << 3;
        else
            cout << 2;

        cout << endl;
    }
}