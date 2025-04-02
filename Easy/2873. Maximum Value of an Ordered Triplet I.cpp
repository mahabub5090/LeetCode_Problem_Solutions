// Problem Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
      int n=nums.size();
      vector<int>lm(n,0),rm(n,0);
      for(int i=1;i<n;i++){
        lm[i]=max(lm[i-1],nums[i-1]);
        rm[n-i-1]=max(rm[n-i],nums[n-i]);
      }

      long long ans=0;
      for(int i=1;i<n-1;i++){
        ans=max(ans,(long long)(lm[i]-nums[i])*rm[i]);
      }
      return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);