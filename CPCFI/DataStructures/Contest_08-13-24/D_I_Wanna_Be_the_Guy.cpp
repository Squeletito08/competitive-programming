#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n; 
    cin >> n; 

    unordered_set<int> niveles; 

    int p; 
    cin >> p; 

    for(int i = 0; i < p; i++){
        int x; 
        cin >> x; 
        niveles.insert(x); 
    }

    int q; 
    cin >> q; 

    for(int i = 0; i < q; i++){
        int x; 
        cin >> x; 
        niveles.insert(x);
    }

    if(niveles.size() == n){
        cout << "I become the guy.";
    }
    else{
        cout << "Oh, my keyboard!"; 
    }

    cout << "\n"; 
    
}