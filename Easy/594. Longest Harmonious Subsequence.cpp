// Problem Link: https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30

// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int ans=0,start=nums[0],cnt=1,same=1,diff=0;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==start)same++;
//             else if(nums[i]==start+1)diff++;
//             else{
//                 if(same && diff){
//                     cnt=same+diff;
//                     ans=max(ans,cnt);
//                 }
//                 else cnt=0;
//                 if(nums[i]-nums[i-1]==1){
//                     start=nums[i-1];
//                     cnt=1+diff;
//                     same=diff;
//                     diff=1;
//                 }
//                 else{
//                     start=nums[i];
//                     cnt=1;
//                     same=1;
//                     diff=0;
//                 }
//             }
//         }
//         if(same && diff){
//             cnt=same+diff;
//             ans=max(ans,cnt);
//         }
//         return ans;
//     }
// };

// Time Complexity : O(NlogN + N) => O(NlogN);
// Space Complexity: O(1);

// Way : 2=>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &c:nums)mp[c]++;
        int ans=0;
        for(auto &c:mp){
            if(mp.count(c.first+1))ans=max(ans,c.second+mp[c.first+1]);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);