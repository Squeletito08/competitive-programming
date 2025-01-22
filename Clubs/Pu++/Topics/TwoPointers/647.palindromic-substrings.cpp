/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    int palImpar(string& s, int a){
        int n = s.size(); 
        int i = a, j = a; 
        int ctd = 0; 

        while(i >= 0 && j < n && s[i] == s[j]){
            ctd++; 
            i--; 
            j++; 
        }

        return ctd; 
    }

    int palPar(string& s, int a, int b){
        int n = s.size();
        int i = a, j = b; 
        int ctd = 0; 

        while(i >= 0 && j < n && s[i] == s[j]){
            ctd++; 
            i--; 
            j++; 
        }

        return ctd; 
    }

    int countSubstrings(string s) {
        int ctd = 0; 
        int n = s.size(); 

        for(int i = 0; i < n; i++){
            ctd += palImpar(s, i);
            ctd += palPar(s, i, i+1); 
        }

        return ctd; 
    }


};


int main(){
    Solution sol; 
    string s; cin >> s; 

    int num = sol.countSubstrings(s); 
    cout << endl << num << endl; 
    return 0; 
}
// @lc code=end

