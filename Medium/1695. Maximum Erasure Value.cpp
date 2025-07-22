// Problem Link: https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0,cnt=0;
        
        while(j<n){
            cnt+=nums[j];
            mp[nums[j]]++;
            j++;

            while(mp[nums[j-1]]!=1){
                cnt-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);