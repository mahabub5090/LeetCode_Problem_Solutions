// Problem Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-04-28

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,i=0,j=0,n=nums.size();
        long long score=0;
        while(j<n){
            int len=j-i;
            if(len)score/=len;
            score+=nums[j++],score*=++len;
            while(i<n && score>=k){
                score/=len--;
                score-=nums[i++];
                score*=len;
            }
            if(score<k)ans+=len;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);