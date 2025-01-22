#include <bits/stdc++.h>
using namespace std; 

int main(){
    int t; 
    cin >> t; 
    while(t--){
        int k; 
        cin >> k; 
        string stu; 
        cin >> stu; 

        int primeraA = -1; 

        for(int i = 0; i < k; i++){
            if(stu[i] == 'A'){
                primeraA = i; 
                break; 
            }
        }

        int contadorP = 0; 
        int cont = 0; 

        if(primeraA == -1){
            cout << 0 << endl; 
        }
        else{
            for(int i = primeraA; i < k; i++){
                if(stu[i] == 'A'){
                    if(cont > contadorP){
                        contadorP = cont; 
                    }
                    cont = 0; 
                }
                else{
                    cont++; 
                }
            }

            if(cont > contadorP){
                contadorP = cont; 
            }

            cout << contadorP << endl; 
        }


    }


}