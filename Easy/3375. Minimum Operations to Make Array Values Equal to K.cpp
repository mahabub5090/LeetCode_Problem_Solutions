// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto &c:nums){
            mp[c]++;
            if(c<k)return -1;
        }
        return mp.size()-(mp[k]>0);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);