// Problem Link: https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size(),mn=arrays[0][0],mx=arrays[0][arrays[0].size()-1];
        int ans=0;
        for(int i=1;i<n;i++){
            int temp=max(mx-arrays[i][0],arrays[i][arrays[i].size()-1]-mn);
            ans=max(ans,temp);
            mn=min(mn,arrays[i][0]);
            mx=max(mx,arrays[i][arrays[i].size()-1]);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);