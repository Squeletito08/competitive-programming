#include <bits/stdc++.h>
using namespace std; 

int main(){
    int t; 
    cin >> t; 
    while(t--){
        int a; 
        cin >> a; 

        double x = 360 / ((180 - a) + 0.0); 
        int xInt = x;

        if(x - xInt == 0)
            cout << "YES"; 
        else
            cout << "NO"; 

        cout << "\n"; 
    }
}