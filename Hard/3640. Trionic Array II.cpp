// Problem Link: https://leetcode.com/problems/trionic-array-ii/description/?envType=daily-question&envId=2026-02-04

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        int p,q,j;
        long long maxSum,sum,res,ans=LLONG_MIN;

        for(int i=0;i<n;i++){
            j=i+1;
            res=0;

            while(j<n && nums[j-1]<nums[j])j++;
            p=j-1;
            if(p==i)continue;

            res+=nums[p]+nums[p-1];
            for(;j<n && nums[j-1]>nums[j];j++)res+=nums[j];
            q=j-1;

            if(q==p || q==n-1 || (nums[j]<=nums[q])){
                i=q;
                continue;
            }
            
            res+=nums[q+1];
            sum=0;
            maxSum=0;
            for(int k=q+2;k<n && nums[k]>nums[k-1];k++){
                sum+=nums[k];
                maxSum=max(maxSum,sum);
            }

            res+=maxSum;
            sum=0;
            maxSum=0;
            for(int k=p-2;k>=i;k--){
                sum+=nums[k];
                maxSum=max(maxSum,sum);
            }

            res+=maxSum;
            ans=max(ans,res);
            i=q-1;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);