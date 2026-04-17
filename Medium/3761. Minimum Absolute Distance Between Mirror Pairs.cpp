// Problem Link: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17

class Solution {
public:
    int mirror(int num){
        int ans=0;
        while(num%10==0)num/=10;
        while(num){
            ans=(ans*10)+num%10;
            num/=10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,queue<int>>mp;
        for(int i=0;i<n;i++)mp[nums[i]].push(i);
        int ans=n;
        for(int i=0;i<n;i++){
            auto &q=mp[mirror(nums[i])];
            while(q.size() && i>=q.front())q.pop();
            if(q.size())ans=min(ans,q.front()-i);
        }
        return ans==n?-1:ans;
    }
};

// Time Complexity : O(N) + O(N*D+N) => O(N);
// Space Complexity: O(N);
// D <= 6; // length of 1e5;