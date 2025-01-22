/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        int n = nums.size(); 
        vector<vector<int>> res; 

        for(int k = 0; k < n - 2; k++){
            if(k > 0 && nums[k] == nums[k-1]) continue; 

            int suma = - nums[k]; 

            int i = k+1; 
            int j = n-1; 

            while(i < j){
                int aux = nums[i] + nums[j]; 
                if(aux == suma){
                    res.push_back({nums[k], nums[i], nums[j]}); 
                    i++; 
                    j--; 
                }

                if(aux < suma){
                    i++; 
                }

                if(aux > suma){
                    j--; 
                }

                while(i < j && nums[i] == nums[i-1]) i++; 
                while(i < j && j < n-1 && nums[j] == nums[j+1]) j--; 
            }
        }

        return res; 
    }
};

int main(){
    Solution sol; 
    vector<int> nums; 
    int n; cin >> n; 

    for(int i = 0; i < n; i++){
        int x; cin >> x; 
        nums.push_back(x); 
    }

    vector<vector<int>> res = sol.threeSum(nums);
    n = res.size(); 
    cout << "[";
    for(int i = 0; i < n; i++){
        cout << "[";
        for(auto x: res[i]){
            cout << x << " "; 
        }
        cout << "], "; 
    }
    cout << "]" << endl; 
}
// @lc code=end

