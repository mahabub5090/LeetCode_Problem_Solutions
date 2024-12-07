// Problem Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/submissions/1472812261/?envType=daily-question&envId=2024-12-07

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=l+(r-l)/2;
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+=(nums[i]-1)/mid;
            }
            if(cnt<=maxOperations)r=mid;
            else l=mid+1;
        }
        return r;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);