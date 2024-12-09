// Problem Link: https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>pref(nums.size(),0);
        vector<bool>ans;
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1];
            if(nums[i-1]%2==nums[i]%2)pref[i]++;
        }
        for(auto &c:queries){
            int cnt=pref[c[1]]-(c[0]?pref[c[0]]:0);
            ans.push_back(cnt==0);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);