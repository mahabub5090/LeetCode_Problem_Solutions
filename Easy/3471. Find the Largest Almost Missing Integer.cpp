// Problem Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();

        if(k>1 && k<n){
            int firstCnt=0, lastCnt=0;
            for(auto &c:nums){
                if(c==nums[0]) firstCnt++;
                if(c==nums[n-1]) lastCnt++;

                if(firstCnt>1 && lastCnt>1) return -1;
            }
            if(firstCnt>1) return nums[n-1];
            if(lastCnt>1) return nums[0];

            return max(nums[0],nums[n-1]);
        }

        if(k==n) return *max_element(nums.begin(),nums.end());

        int ans=-1;
        unordered_map<int,int> mp;
        for(auto &c:nums) mp[c]++;
        for(auto &[val,freq]:mp) if(freq==1) ans=max(ans,val);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);