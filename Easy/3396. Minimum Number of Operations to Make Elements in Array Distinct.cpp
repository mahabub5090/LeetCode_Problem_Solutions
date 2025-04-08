// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08

class Solution {
public:
    int have(int i,auto &nums){
        map<int,int>mp;
        for(;i<nums.size();i++)mp[nums[i]]++;
        for(auto &c:mp)if(c.second>1)return 1;
        return 0;
    }
    int minimumOperations(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i+=3){
            if(have(i,nums)==0)return i/3;
        }
        return (n+2)/3;
    }
};

// Time Complexity : O((N^2)*logN);
// Space Complexity: O(N);