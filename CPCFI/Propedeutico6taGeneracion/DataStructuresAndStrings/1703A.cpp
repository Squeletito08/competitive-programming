#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (s == "yes")
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}