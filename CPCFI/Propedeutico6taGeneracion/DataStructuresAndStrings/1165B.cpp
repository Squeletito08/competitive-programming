#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int dias = 1;

    while (!pq.empty())
    {
        if (pq.top() >= dias)
            dias++;

        pq.pop();
    }

    cout << dias - 1 << endl;
}