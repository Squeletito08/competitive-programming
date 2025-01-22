#include <bits/stdc++.h>
using namespace std; 

int main(){
    int t; 
    cin >> t; 
    while(t--){
        int n, a, q; 
        cin >> n; 
        cin >> a; 
        cin >> q; 
        string notif; 
        cin >> notif; 

        string res; 

        int conectados = 0; 

        for(int i = 0; i < q; i++){
            if(notif[i] == '+')
                conectados++; 
        }

        int desconectados = q - conectados; 

        if(a == n){
            res = "YES"; 
        }
        else{
            if(a + conectados >= n && a - desconectados + conectados < n){
                res = "MAYBE";
            }
            else if(a + conectados >= n){
                res = "YES";
            }
            else {
                res = "NO"; 
            }
        }

        cout << res << "\n"; 

    }
}
