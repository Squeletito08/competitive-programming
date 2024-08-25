#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n; 
    cin >> n;

    vector<int> vec(n);

    for(int i =0 ; i< n; i++)
        cin >> vec[i];

    long long int anterior = vec[0]; 
    long long int contador = 0; 

    for(int i = 1; i < n; i++){
        if(vec[i] < anterior){
            contador += anterior - vec[i]; 
        }
        else{
            anterior = vec[i]; 
        }
    }

    cout << contador; 
}