#include <bits/stdc++.h>
using namespace std; 

string hora(string cadena){
    string horario = "AM"; 

    int hora = stoi(cadena.substr(0,2)); 
    string respuesta = ""; 

    if(hora >= 12)
        horario = "PM";

    if(hora == 12){
        return cadena + " " + horario; 
    }

    if(hora == 0){
        return "12:" + cadena.substr(3, 2) + " " + horario;
    }

    if(hora % 12 < 10){
        respuesta += "0"; 
        respuesta += to_string(hora % 12) + ":" + cadena.substr(3,2) + " " + horario; 
    }
    else{
        respuesta += to_string(hora % 12) + ":" + cadena.substr(3,2) + " " + horario; 
    }
    

   return respuesta;  
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        string cadena; 
        cin >> cadena; 

        cout << hora(cadena) << "\n"; 
    }
}