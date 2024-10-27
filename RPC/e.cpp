#include <bits/stdc++.h>
using namespace std;

string str;
int i=0, m;

int buscaRest(char ch) {
  int r=0;
  while(str[i]!=ch & i<str.size()) {
    r++;
    i++;
  }
  return r;
}



int buscaTam(char ch) {
  int r=0;
  while(str[i]==ch & i<str.size()) {
    r++;
    i++;
  }
  return r;
}



int maxChar(char ch) {
  int max=0, rest=0, tam=0;
  queue<int> cola;
  
  while(i < str.size()){
    
    int t=buscaTam(ch), r=buscaRest(ch);
    
    cola.push(t);
    cola.push(r);
    
    tam += t;
    if(tam > max) max=tam;
    
    rest += r;
    while(rest > m) {
      tam -= cola.front();
      cola.pop();
      rest -= cola.front();
      cola.pop();
    }
    
  }
  return max;
} 



int main() 
{
  int max=0, mc;
  cin >> str >> m;
  for(char c='a'; c<='z'; c++) {
    i=0;
    mc=maxChar(c);
    if(mc > max) max = mc;
  }
  cout << max << endl;
  
}