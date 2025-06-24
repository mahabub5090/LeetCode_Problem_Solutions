// Problem Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(i-j)<=k && nums[j]==key){
                    ans.push_back(i);
                    break;
                }
            }
       }
       return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);