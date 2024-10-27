#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  
  set<int> c,java;
  
  for(int i=0;i<m;i++) {
    int x,y; cin >> x >> y;
    if(y == 1) {
      c.insert(x);
    } else if (y == 2) {
      java.insert(x);
    }
  }

  set<int> res; 

  for(auto x: c){
    if(java.count(x)){
      res.insert(x);
    }
  }

  for(auto x: res){
    cout << x << endl; 
  }

}
