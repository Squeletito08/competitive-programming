#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int t; 
    cin >> t; 
    while(t--){
        int n, k; 
        cin >> n; 
        cin >> k; 

        cout << k*(n-1)+1; 
        cout << "\n"; 
    }
}