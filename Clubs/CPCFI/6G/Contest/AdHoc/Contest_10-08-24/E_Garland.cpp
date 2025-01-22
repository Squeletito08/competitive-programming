#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int t; 
    cin >> t; 
    while(t--){
        string focos; 
        cin >> focos; 

        unordered_set<char> focosConj; 

        for(int i = 0; i < focos.size(); i++)
            focosConj.insert(focos[i]); 

        if(focosConj.size() == 4 || focosConj.size() == 3){
            cout << 4; 
        }
        else if(focosConj.size() == 2){
            cout << 6; 
        }
        else {
            cout << -1; 
        }

        cout << "\n"; 

    }
}