// Problem Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start,j=start,n=nums.size();
        int ans=n;
        while(i>=0 || j<n){
            if(i>=0 && nums[i]==target)ans=min(ans,start-i);
            if(j<n && nums[j]==target)ans=min(ans,j-start);
            i--,j++;
            if(ans!=n)break;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);