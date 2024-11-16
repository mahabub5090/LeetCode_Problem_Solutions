// Problem Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;i<nums.size()-k+1;i++){
            int ok=1;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]+1!=nums[j+1]){
                    ok=0;
                    break;
                }    
            }
            ans.push_back(ok?nums[i+k-1]:-1);
        }
        return ans;
    }
};

// Time Complexity : O(N*k) => O(N^2);
// Space Complexity: O(N);