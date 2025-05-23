// Problem Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2025-05-23

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int>netChange;
        long long nodeSum=0;

        for(int i=0;i<n;i++){
            netChange.push_back((nums[i]^k)-nums[i]);
            nodeSum+=nums[i];
        }

        sort(netChange.rbegin(),netChange.rend());

        for(int i=0;i<n;i+=2){
            if(i+1==n)break;

            long long pairSum=netChange[i]+netChange[i+1];
            nodeSum+=max(0ll,pairSum);
        }
        return nodeSum;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);