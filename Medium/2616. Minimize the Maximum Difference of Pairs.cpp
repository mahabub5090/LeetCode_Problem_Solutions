// Problem Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13

class Solution {
public:
    int countValidPairs(int mid,auto &nums){
        int n=nums.size(),i=0,cnt=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid)cnt++,i++;
            i++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<=r){
            int mid=(l+r)/2;
            if(countValidPairs(mid,nums)>=p)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};

// Time Complexity : O(NlogN + Nlog(max_diff)) => O(NlogN);
// Space Complexity: O(1);
// "max_diff" is maximam difference between any pair in the nums array.
