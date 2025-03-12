// Problem Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int up=upper_bound(nums.begin(),nums.end(),-1)-nums.begin();
        int lw=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        cout<<up<<" "<<lw<<endl;
        return max(up,(int)nums.size()-lw);
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);