#include <bits/stdc++.h>
using namespace std;

bool es_vocal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!es_vocal(s[i]))
        {
            res += ".";
            res += s[i];
        }
    }
    cout << res << endl;
}
