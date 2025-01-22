#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        int x, y;
        cin >> x >> y;

        cout << min(x, y) << " " << max(x, y) << endl;
    }
}