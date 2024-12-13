// Problem Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        map<int,set<int>>mp;
        map<int,int>vis;
        for(int i=0;i<nums.size();i++)mp[nums[i]].insert(i);
        sort(nums.begin(),nums.end());
        for(auto &c:nums){
            for(auto &cc:mp[c]){
                if(vis[cc]){
                    mp[c].erase(cc);
                    continue;
                }
                ans+=c;
                vis[cc]=1;
                vis[cc-1]=1;
                vis[cc+1]=1;
                mp[c].erase(cc);
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);