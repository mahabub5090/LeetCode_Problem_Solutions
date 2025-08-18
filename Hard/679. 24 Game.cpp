// Problem Link: https://leetcode.com/problems/24-game/description/?envType=daily-question&envId=2025-08-18

class Solution {
public:
    double EPS=1e-6;
    vector<double>compute(double a,double b){
        vector<double>poss;
        poss.push_back(a+b);
        poss.push_back(a-b);
        poss.push_back(-a+b);
        poss.push_back(a*b);
        if(fabs(a)>EPS)poss.push_back(b/a);
        if(fabs(b)>EPS)poss.push_back(a/b);
        return poss;
    }
    int dfs(auto &nums){
        if(nums.size()==1)return fabs(nums[0]-24.0)<EPS;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                vector<double>next;
                for(int k=0;k<nums.size();k++){
                    if(k!=i && k!=j)next.push_back(nums[k]);
                }

                vector<double>poss=compute(nums[i],nums[j]);
                for(auto &c:poss){
                    next.push_back(c);
                    if(dfs(next))return 1;
                    next.pop_back();
                }
            }
        }
        return 0;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(auto &c:cards)nums.push_back((double)c);
        return dfs(nums);
    }
};

// Time Complexity : O(N! * 6^N) => O(4! * 6^4) => O(31104) => O(1);
// Space Complexity: O(N-1) => O(4-1) => O(3) => O(1); 