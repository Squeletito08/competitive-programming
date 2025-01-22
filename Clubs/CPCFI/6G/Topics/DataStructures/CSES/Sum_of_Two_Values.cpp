#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n; 
    int x; 
    cin >> n; 
    cin >> x; 

    vector<int> vi(n); 
    map<int, int> map; 

    for(int i = 0; i < n; i++){
        int a; 
        cin >> a; 
        vi[i] = a; 
        if(!map.count(a)){
            map[a] = i; 
        }
    }

    int a = -1; 
    int b = -1;  

    for(int i = 0; i < n; i++){
        int buscar = abs(x - vi[i]);

        if(map.count(buscar) && i != map[buscar] && (vi[i] + buscar == x)){
            a = i; 
            b = map[buscar]; 
            break; 
        }
    } 

    if( a == -1 && b == -1){
        cout << "IMPOSSIBLE";
    }
    else {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}