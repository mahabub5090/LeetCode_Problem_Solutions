// Problem Link: https://leetcode.com/problems/maximum-matrix-sum/submissions/1461400347/?envType=daily-question&envId=2024-11-24

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0,zero=0,mn=1e9;
        long long ans=0;
        for(auto &c:matrix){
            for(auto &cc:c){
                if(cc==0)zero++;
                else if(cc<0)neg++;
                mn=min(mn,abs(cc));
            }
        }
        if(neg%2==0 || (neg%2 && zero)){
            return ans;
        }
        return ans-abs(2*mn);
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(1);