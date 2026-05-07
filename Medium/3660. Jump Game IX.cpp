// Problem Link: https://leetcode.com/problems/jump-game-ix/description/?envType=daily-question&envId=2026-05-07

class Solution {
public:
    vector<int> ans;
    void process(int r,int rightMin,int rightMax,auto &nums,auto &prevMaxIndex){
        auto [prevMax,prevIdex]=prevMaxIndex[r];
        int currMax=prevMax<=rightMin?prevMax:rightMax;

        int nextRightMin=min(prevMax,rightMin);
        for(int i=prevIdex;i<=r;i++){
            ans[i]=currMax;
            nextRightMin=min(nextRightMin,nums[i]);
        }

        if(prevIdex==0) return;
        process(prevIdex-1,nextRightMin,currMax,nums,prevMaxIndex);
    }

    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        ans.resize(n,0);

        vector<pair<int,int>>prevMaxIndex(n);
        pair<int,int> prev={INT_MIN,-1};
        for(int i=0;i<n;i++){
            if(nums[i]>prev.first) prev={nums[i],i};
            prevMaxIndex[i]=prev;
        }

        process(n-1,INT_MAX,0,nums,prevMaxIndex);
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N) + O(N) + O(N) => O(N);