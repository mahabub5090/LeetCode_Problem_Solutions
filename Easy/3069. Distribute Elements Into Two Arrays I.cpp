// Problem Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans={nums[0]}, rest={nums[1]};
        for(int i=2;i<nums.size();i++){
            auto &point=ans.back()>rest.back()?ans:rest;
            point.push_back(nums[i]);
        }
        ans.insert(ans.end(),rest.begin(),rest.end());
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N) + O(N) => O(N);