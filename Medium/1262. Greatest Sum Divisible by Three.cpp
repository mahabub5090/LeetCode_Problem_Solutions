// Problem Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/description/?envType=daily-question&envId=2025-11-23

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>cnt(3);
        for(auto &c:nums)cnt[c%3].push_back(c);
        for(auto &c:cnt)sort(c.begin(),c.end());

        int tt=accumulate(nums.begin(),nums.end(),0);
        int remove=INT_MAX;

        if(tt%3==0)remove=0;
        if(tt%3==1){
            if(cnt[1].size()){
                remove=min(remove,cnt[1][0]);
            }
            if(cnt[2].size()>=2){
                remove=min(remove,cnt[2][0]+cnt[2][1]);
            }
        }
        if(tt%3==2){
            if(cnt[2].size()){
                remove=min(remove,cnt[2][0]);
            }
            if(cnt[1].size()>=2){
                remove=min(remove,cnt[1][0]+cnt[1][1]);
            }
        }
        return tt-remove;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);