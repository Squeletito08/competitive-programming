#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n, l; 
    cin >> n; 
    cin >> l; 

    vector<int> lanters(n); 

    for(int i = 0;  i <= n; i++){
        cin >> lanters[i]; 
    }

    sort(lanters.begin(), lanters.end());   


    int disMax = 0; 

    for(int i = 0; i < n; i++){
        if(i+1 < n){
            if(lanters[i+1] - lanters[i] > disMax)
                disMax = lanters[i+1] - lanters[i]; 
        }
    }

    int maximo = max(lanters[0], l - lanters[n-1]); 

    double res = disMax / 2.0 > maximo ? disMax / 2.0 : maximo; 
    
    cout << fixed << setprecision(10) << res << endl; 


}