#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<char, int> val;
    val['I'] = 1;
    val['V'] = 5; 
    val['X'] = 10; 
    val['L'] = 50; 
    val['C'] = 100; 
    val['D'] = 500; 
    val['M'] = 1000; 

    int n; cin >> n;

    for(int i=0; i<n; i++) {
        string q; cin >> q;
        int sz = q.size(); 
        int max=val[toupper(q[sz-1])], acc=max, ant=0, num=0;

        //cout << "q " << q << "\n";
        //cout << ant << " "  << max << " "  << acc << " " << num << "\n";
        for(int j=sz-2; j>=0; j--) {
            ant = val[toupper(q[j])];

            if(ant < max) {
                acc -= ant;
            } 
            else {
                max = ant;
                num += acc;
                acc = max;
            }
            //cout << ant << " "  << max << " "  << acc << " " << num << "\n";
        }
        num += acc;
        cout << num << "\n";
    }
}