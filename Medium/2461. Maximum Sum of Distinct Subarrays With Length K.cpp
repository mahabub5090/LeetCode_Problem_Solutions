// Problem Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0;
        map<int,int>mp;
        int i=0,j=0;
        while(j<nums.size()){
            if(j<k)sum+=nums[j],mp[nums[j]]++,j++;
            else{
                sum-=nums[i];sum+=nums[j];
                mp[nums[j]]++;
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++,j++;
            }
            if(mp.size()==k)ans=max(ans,sum);
        }
        return ans;
    }
};

// Time Complexity : O(N*logK) => O(NlogN);
// Space Complexity: O(K) => O(N);
// K is the total unique element in the given array.


