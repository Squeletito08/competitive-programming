#include <bits/stdc++.h>
using namespace std; 

int main () {
    int t;
    cin >> t; 

    while (t--){
        int n;
        cin >> n; 
        vector<vector<char>> matriz(n, vector<char>(n, '0')); 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matriz[i][j]; 
            }
        }

        int unosFilaActual = false; 
        int unosFilaAnt = 0; 
        bool triangulo = true;

        for(int i = 0; i< n; i++){
            for(int j = 0; j < n ; j++){
                if(matriz[i][j] == '1'){
                    unosFilaActual++; 
                }
            }
            if(unosFilaActual && unosFilaAnt && unosFilaActual == unosFilaAnt ){
                triangulo = false; 
            }
            unosFilaAnt = unosFilaActual; 
            unosFilaActual = 0; 
        }

        if(triangulo){
            cout << "TRIANGLE"; 
        }
        else{
            cout << "SQUARE"; 
        }

        cout << endl; 
    }
}