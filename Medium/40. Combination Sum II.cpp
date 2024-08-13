// Problem Link: https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13

class Solution {
public:
    void findComb(int id,int target,auto &can,auto &vc,auto &ans){
        if(target==0){
            ans.push_back(vc);return;
        }

        for(int i=id;i<can.size();i++){
            if(i>id && can[i]==can[i-1])continue;
            if(can[i]>target)break;
            vc.push_back(can[i]);
            findComb(i+1,target-can[i],can,vc,ans);
            vc.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>vc;
        findComb(0,target,candidates,vc,ans);
        return ans;
    }
};

// Time Complexity : O(NlogN)+O((2^N)*N) => O((2^N)*N);
// Space Complexity: O(N)+O((2^N)*N) => O((2^N)*N);