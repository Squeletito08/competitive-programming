#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L, W, H;
  cin >> L >> W >> H;
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];

  int maximo = -INT_MAX;

  int a = 0, b = 0, c = 0;

  a = L / v[0];
  b = W / v[1];
  c = H / v[2];
  maximo = max(a * b * c, maximo);

  a = L / v[0];
  b = W / v[2];
  c = H / v[1];
  maximo = max(a * b * c, maximo);

  a = L / v[2];
  b = W / v[0];
  c = H / v[1];
  maximo = max(a * b * c, maximo);

  a = L / v[2];
  b = W / v[1];
  c = H / v[0];
  maximo = max(a * b * c, maximo);

  a = L / v[1];
  b = W / v[2];
  c = H / v[0];
  maximo = max(a * b * c, maximo);

  a = L / v[1];
  b = W / v[0];
  c = H / v[2];
  maximo = max(a * b * c, maximo);

  cout << maximo << endl;
}