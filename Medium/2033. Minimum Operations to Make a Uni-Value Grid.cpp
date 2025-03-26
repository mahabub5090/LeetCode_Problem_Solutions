// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26

class Solution {
public:
    int possible(int x,int mid,auto &grid){
        int ans=0;
        for(auto &c:grid){
            for(auto &cc:c){
                int dist=abs(cc-mid);
                if(dist%x)return -1;
                ans+=dist/x;
            }
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>vc;
        for(auto &c:grid)for(auto &cc:c)vc.push_back(cc);
        sort(vc.begin(),vc.end());
        return possible(x,vc[vc.size()/2],grid);
    }
};

// Time Complexity : O((M*N)log(m*n)) => O((N^2)LogN)
// Space Complexity: O(M*N) => O(N^2);