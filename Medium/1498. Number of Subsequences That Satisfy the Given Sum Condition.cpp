// Problem Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29 .

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size(),mod=1e9+7;
        sort(nums.begin(),nums.end());

        vector<long long>pw(n);pw[0]=1;
        for(int i=1;i<n;i++)pw[i]=2*pw[i-1],pw[i]%=mod;

        long long ans=0,i=0,j=n-1;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans+=pw[j-i];
                ans%=mod;
                i++;
            }
            else j--;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN*(2*N)) => O(NlogN);
// Space Complexity: O(N);