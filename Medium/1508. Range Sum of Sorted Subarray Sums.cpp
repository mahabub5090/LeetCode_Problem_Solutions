// Problem Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        vector<int>vc;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                cnt+=nums[j];
                vc.push_back(cnt);
            }
        }
        sort(vc.begin(),vc.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans+=vc[i];
            ans%=mod;
        }
        return ans;
    }
};

// Time Complexity : O(N^2 + NlogN + N) => O(N^2);
// Space Complexity: O(N);