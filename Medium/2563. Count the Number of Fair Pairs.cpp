// Problem Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/1451650937/?envType=daily-question&envId=2024-11-13

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0,pos=1;
        for(auto &c:nums){
            auto up=upper_bound(nums.begin()+pos,nums.end(),upper-c);
            auto lb=lower_bound(nums.begin()+pos,nums.end(),lower-c);
            cnt+=up-lb;
            pos++;
        }
        return cnt;
    }
};

// Time Complexity : O(NlogN) + O(N*(2*logN)) => O(NlogN);
// Space Complexity: O(1);