// Problem Link: https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mp;for(auto &c:nums)mp[c]++;
        int i=0,n=nums.size(),dominant;
        for(auto &c:mp)if(c.second>n/2)dominant=c.first;
        int cnt=0;
        while(cnt*2<=i && i<n)cnt+=nums[i++]==dominant;
        cnt=0;
        int j=i;
        for(;j<n;j++)cnt+=nums[j]==dominant;
        return (cnt*2>(j-i)?--i:-1);
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(N);