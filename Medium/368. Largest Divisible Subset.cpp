// Problem Link: https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2025-04-06

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1),prev(n,-1);
        int ml=0,li=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>ml)ml=dp[i],li=i;
        }

        vector<int>ans;
        while(li!=-1){
            ans.push_back(nums[li]);
            li=prev[li];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N^2) => O(N^2);
// Space Complexity: O(N);