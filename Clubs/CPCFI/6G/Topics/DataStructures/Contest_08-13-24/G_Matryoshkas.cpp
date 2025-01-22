#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        multiset<int> matri; 

        for(int i = 0; i < n; i++){
            int x; 
            cin >> x; 
            matri.insert(x); 
        }

        int contador = 1; 
        auto primero = matri.begin(); 
        int elem = *primero; 
        matri.erase(primero); 

        elem++; 

        while(!matri.empty()){
            auto sig = matri.find(elem);
            if(sig == matri.end()){
                contador++; 
                elem = *matri.begin(); 
            }
            else{
                matri.erase(sig); 
                elem++; 
            }
        }



        cout << contador << "\n"; 
    }
}