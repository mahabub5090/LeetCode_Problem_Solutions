// Problem Link: https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0,n=nums.size();
        unordered_map<int,int>e,o;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)e[nums[j]]++;
                else o[nums[j]]++;

                if(e.size()==o.size())ans=max(ans,j+1-i);
            }
            e.clear();
            o.clear();
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);