// Problem Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2025-06-18

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        for(auto &c:nums){
            temp.push_back(c);
            if(temp.size()==3){
                ans.push_back(temp);
                temp.clear();
            }
        }
        for(auto &c:ans){
            if(c[2]-c[0]>k)return {};
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1); 