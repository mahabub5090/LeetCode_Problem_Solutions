// Problem Link: https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(auto &c:nums)r+=c==0,w+=c==1,b+=c==2;
        int i=0;
        while(r--)nums[i++]=0;
        while(w--)nums[i++]=1;
        while(b--)nums[i++]=2;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);