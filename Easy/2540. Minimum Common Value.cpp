// Problem Link: https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-18

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i]==nums2[j]) return nums1[i];

            if(nums1[i]<nums2[j])i++;
            else j++;
        }
        return -1;
    }
};

// Time Complexity : O(N + M) => O(N);
// Space Complexity: O(1);