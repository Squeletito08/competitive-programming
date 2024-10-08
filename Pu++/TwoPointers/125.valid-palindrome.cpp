/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size(); 
        
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); 

        string aux = ""; 

        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                aux += s[i]; 
            }
        }

        n = aux.size(); 

        int i = 0, j = n-1; 

        while(i < j){
            if(aux[i] != aux[j]){
                return false; 
            }
            i++; 
            j--;
        }

        return true; 
    }
};

int main(){
    Solution sol; 
    string s; cin >> s; 
    bool res = sol.isPalindrome(s); 
    cout << res << endl; 
    return 0; 
}
// @lc code=end

