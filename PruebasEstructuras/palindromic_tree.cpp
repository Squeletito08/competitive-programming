#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define SZ(n) (int)size(n)
using ll = long long;

struct palindromic_tree
{
  static const int SIGMA = 26;
  struct Node
  {
    int len, link, to[SIGMA];
    int inicio;
    ll cnt;
    Node(int len, int link = 0, ll cnt = 1, int inicio = 0) : len(len), link(link), cnt(cnt), inicio(inicio)
    {
      memset(to, 0, sizeof(to));
    }
  };
  vector<Node> ns;
  int last;
  palindromic_tree() : last(0)
  {
    ns.pb(Node(-1));
    ns.pb(Node(0));
  }
  void add(int i, string &s)
  {
    int p = last, c = s[i] - 'a';
    while ((i - ns[p].len) < 0 || s[i - ns[p].len - 1] != s[i])
      p = ns[p].link;
    if (ns[p].to[c])
    {
      last = ns[p].to[c];
      ns[last].cnt++;
    }
    else
    {
      int q = ns[p].link;
      while ((i - ns[q].len - 1) < 0 || s[i - ns[q].len - 1] != s[i])
        q = ns[q].link;
      q = max(1, ns[q].to[c]);
      last = ns[p].to[c] = SZ(ns);
      ns.pb(Node(ns[p].len + 2, q, 1, i));
    }
  }
};

void solve()
{
  string s;
  cin >> s;

  palindromic_tree tree;
  for (int i = 0; i < SZ(s); i++)
  {
    tree.add(i, s);
  }

  int maxi = -INT_MAX;
  int comienzo = -1;

  for (int i = 2; i < tree.ns.size(); i++)
  {
    if (tree.ns[i].len > maxi)
    {
      maxi = tree.ns[i].len;
      comienzo = tree.ns[i].inicio;
    }
  }

  int i = comienzo - maxi + 1;
  int m = i + maxi;

  for (; i < m; i++)
  {
    cout << s[i];
  }
  cout << endl;
}

int main()
{

  solve();
  return 0;
}