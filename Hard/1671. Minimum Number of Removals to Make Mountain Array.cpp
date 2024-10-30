// Problem Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/?envType=daily-question&envId=2024-10-30

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,0),lds(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i])lis[i]=max(lis[i],1+lis[j]);
            }
        }
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]<nums[i])lds[i]=max(lds[i],1+lds[j]);
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if(lis[i]>0 && lds[i]>0)
                ans=min(ans,n-lis[i]-lds[i]-1);
        }
        return ans;
    }
};

// Time Complexity : O(2*N^2) + O(N) => O(N^2);
// Space Complexity: O(2*N) => O(N);