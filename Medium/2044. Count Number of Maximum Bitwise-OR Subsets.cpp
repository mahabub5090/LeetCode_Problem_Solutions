// Problem Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18

class Solution {
public:
    void dfs(int i,auto &vc,int cor,int mor,int &cnt){
        if(i==vc.size())return;
        if((cor|vc[i])==mor)cnt++;
        dfs(i+1,vc,cor|vc[i],mor,cnt);
        dfs(i+1,vc,cor,mor,cnt);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mor=0;
        for(auto &c:nums)mor|=c;
        int cnt=0;
        dfs(0,nums,0,mor,cnt);
        return cnt;
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(N); // for call stack;