// Problem Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08

class Solution {
public:
    int n,m;
    vector<int>nums,nums2;
    vector<vector<int>>memo;
    
    int dp(int i,int j){
        if(i==n || j==m)return -1e9;

        if(memo[i][j]!=INT_MIN)return memo[i][j];

        int take=nums[i]*nums2[j];

        int ans=max({
            take+dp(i+1,j+1),
            take,
            dp(i+1,j),
            dp(i,j+1)
        });

        return memo[i][j]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {;
        this->nums=nums1;
        this->nums2=nums2;
        n=nums.size(),m=nums2.size();

        memo.assign(n,vector<int>(m,INT_MIN));
        return dp(0,0);
    }
};

// Time Complexity : O(2*N*M) => O(N^2);
// Space Complexity: O(N+M) + O(N*M) => O(N^2);