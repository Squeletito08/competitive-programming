#include <bits/stdc++.h>
using namespace std; 


int main(){
    int t; 
    cin >> t; 

    while(t--){
        long long int n, k; 
        cin >> n; 
        cin >> k; 

        if( n % 2 == 0  || k == 1 || k == n)
            cout << "YES"; 
        else{
            if((n-k) % 2 == 0)
                cout << "YES"; 
            else 
                cout << "NO"; 
        }
        cout << "\n"; 
    }

}