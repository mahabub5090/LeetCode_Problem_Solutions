// Problem Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int j=0,ans=0;
        for(int i=0;i<n;i++){
            while(j<m && nums1[i]<=nums2[j])j++;
            ans=max(ans,j-i-1);
        }
        return ans;
    }
};

// Time Complexity : O(N + M) => O(N);
// Space Complexity: O(1);
// N = nums1.size(), M = nums2.size();