// Problem Link: https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid)cnt++,i++;
            }
            if(cnt<k)l=mid+1;
            else r=mid;
        }
        return l;
    }
};

// Time Complexity : O(Nlog(max(nums))) => O(NlogN);
// Space Complexity: O(1);