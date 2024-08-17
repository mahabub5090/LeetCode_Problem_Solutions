// Problem Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/description/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<k-1;i++){
            if(nums[i]+1!=nums[i+1]){
                cnt=i+1;
            }
        }
        ans.push_back(cnt==0?nums[k-1]:-1);
        int i=0,j=k,cnt2=0;
        while(j<nums.size()){
            if(k>1 && nums[j-1]+1!=nums[j])cnt=j-i,cnt2=0;
            if(cnt)cnt2++;
            ans.push_back(cnt==cnt2?nums[j]:-1);
            if(cnt==cnt2)cnt=0,cnt2=0;
            i++,j++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);