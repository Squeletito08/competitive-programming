#include <bits/stdc++.h>
using namespace std; 

int main(){
    unordered_set<char> conjunto{'H', 'Q', '+', '9'}; 


    string cadena; 
    cin >> cadena; 

    bool res = false; 

    for(int i = 0; i < cadena.size(); i++){
        if(conjunto.count(cadena[i]) > 0 && cadena[i] != '+'){
          res = true; 
          break;   
        }
    }

    if(res)
        cout << "YES"; 
    else
        cout << "NO";
    cout << endl; 

}