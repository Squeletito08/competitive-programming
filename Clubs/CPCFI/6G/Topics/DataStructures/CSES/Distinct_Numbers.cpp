#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    set<int> conjunto;  

    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        conjunto.insert(x); 
    }
    cout << conjunto.size() << endl; 
}