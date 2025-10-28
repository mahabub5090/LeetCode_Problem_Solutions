// Problem Link: https://leetcode.com/problems/make-array-elements-equal-to-zero/?envType=daily-question&envId=2025-10-28

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int tt=accumulate(nums.begin(),nums.end(),0);
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i],tt-=nums[i];
            if(nums[i]==0){
                if(cnt==tt)ans+=2;
                else if(abs(cnt-tt)==1)ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);