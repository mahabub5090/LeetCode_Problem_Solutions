// Problem Link: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/?envType=daily-question&envId=2026-06-26

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pref(n*2+1,0);
        pref[n]=1;
        int cnt=n;

        long long ans=0, prefSum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                prefSum+=pref[cnt];
                cnt++;
            }
            else{
                cnt--;
                prefSum-=pref[cnt];
            }
            
            ans+=prefSum;
            pref[cnt]++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N*2+1) => O(N);