#include <bits/stdc++.h>
using namespace std; 

int main() {
    int t; 
    cin >> t; 
    while(t--){
        int a, b, c, d;
        cin >> a; 
        cin >> b; 
        cin >> c; 
        cin >> d; 

        if(c == a || c == b || d == a || d == b){
            cout << "YES"; 
            continue; 
        }


        int menor = a; 
        int mayor = b; 
        if(a > b){
            menor = b; 
            mayor = a; 
        }

        if(c > menor && c < mayor){
            if(d > menor && d < mayor){
                cout << "NO";
            }
            else{
                cout << "YES"; 
            }
        }
        else{
            if(d > menor && d < mayor){
                cout << "YES";
            }
            else{
                cout << "NO"; 
            }
        }

        cout << endl; 


    }
}