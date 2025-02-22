#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct mint
{
  const static int M = 998244353;
  ll v = 0;
  mint() {}
  mint(ll v) { this->v = (v % M + M) % M; }
  mint operator+(const mint &o) const { return v + o.v; }
  mint &operator+=(const mint &o)
  {
    v = (v + o.v) % M;
    return *this;
  }
  mint operator*(const mint &o) const { return v * o.v; }
  mint operator-(const mint &o) const { return v - o.v; }
  mint &operator-=(const mint &o)
  {
    mint t = v - o.v;
    v = t.v;
    return *this;
  }
  mint operator^(int y) const
  {
    mint r = 1, x = v;
    for (y <<= 1; y >>= 1; x = x * x)
      if (y & 1)
        r = r * x;
    return r;
  }
  mint inv() const
  {
    assert(v);
    return *this ^ M - 2;
  }
  friend istream &operator>>(istream &s, mint &v)
  {
    return s >> v.v;
  }
  friend ostream &operator<<(ostream &s, const mint &v) { return s << v.v; }
  mint operator/(mint o) { return *this * o.inv(); }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node
{
  Node(mint val) : val(val), sum(val), weight(rng()), size(1) {}
  mint val, sum;
  ll weight, size;
  bool rev = false; // whether this range is reversed
  Node *l = nullptr, *r = nullptr;
};

int size(Node *treap) { return treap ? treap->size : 0; }

mint sum(Node *treap) { return treap ? treap->sum : 0; }

void push(Node *treap)
{
  if (!treap)
    return;
  if (treap->rev)
  { // need to reverse this range
    treap->rev = false;
    swap(treap->l, treap->r);
    if (treap->l)
      treap->l->rev ^= true;
    if (treap->r)
      treap->r->rev ^= true;
  }
}

void pull(Node *treap)
{
  if (!treap)
    return;
  push(treap->l), push(treap->r);
  treap->size = size(treap->l) + size(treap->r) + 1;
  treap->sum = sum(treap->l) + sum(treap->r) + treap->val;
}

void merge(Node *&treap, Node *l, Node *r)
{
  push(l), push(r);
  if (!l || !r)
  {
    treap = l ? l : r;
  }
  else if (l->weight > r->weight)
  {
    merge(l->r, l->r, r), treap = l;
  }
  else
  {
    merge(r->l, l, r->l), treap = r;
  }
  pull(treap);
}

void split(Node *treap, Node *&l, Node *&r, int val)
{
  if (!treap)
    return void(l = r = nullptr);
  push(treap);
  if (val > size(treap->l))
  {
    split(treap->r, treap->r, r, val - size(treap->l) - 1), l = treap;
  }
  else
  {
    split(treap->l, l, treap->l, val), r = treap;
  }
  pull(treap);
}

struct Treap
{
  Node *root = nullptr;

  void insert(int i, int x)
  {
    Node *l, *r;
    split(root, l, r, i);
    auto v = new Node(x);
    merge(l, l, v);
    merge(root, l, r);
  }

  void del(int i)
  {
    Node *l, *r;
    split(root, l, r, i);
    split(r, root, r, 1);
    merge(root, l, r);
  }

  void upd(int l, int r, function<void(Node *)> f)
  {
    Node *a, *b, *c;
    split(root, a, b, l);
    split(b, b, c, r - l);
    if (b)
    {
      f(b);
    }
    merge(root, a, b);
    merge(root, root, c);
  }

  template <typename R>
  R query(int l, int r, function<R(Node *)> f)
  {
    Node *a, *b, *c;
    split(root, a, b, l);
    split(b, b, c, r - l);
    assert(b);
    R x = f(b);
    merge(root, a, b);
    merge(root, root, c);
    return x;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  Treap treap;

  // Inicializar el Treap con los valores
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    mint x(val);
    treap.insert(i, x.v);
  }

  // Procesar las consultas
  for (int i = 0; i < m; i++)
  {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1)
    {
      // Reversión de subarray [a, b]
      treap.upd(a - 1, b, [](Node *x)
                { x->rev ^= true; });
    }
    else if (t == 2)
    {
      // Sumar el subarray [a, b]
      cout << treap.query<mint>(a - 1, b, [](Node *x)
                                { return x->sum; })
           << endl;
    }
  }

  return 0;
}
