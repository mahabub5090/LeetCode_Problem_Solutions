// Problem Link: https://leetcode.com/problems/range-product-queries-of-powers/?envType=daily-question&envId=2025-08-11

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod=1e9+7;
        vector<int>bins;
        int rep=1;
        while(n){
            if(n%2)bins.push_back(rep);
            n/=2;
            rep*=2;
        }

        vector<int>ans;
        for(auto &c:queries){
            long long curr=1;
            for(int i=c[0];i<=c[1];i++){
                curr*=bins[i];
                curr%=mod;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

// Time Complexity : O(Q * logN) => O(NlogN);
// Space Complexity: O(Q + logN) => O(N);