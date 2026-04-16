// Problem Link: https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>minDist;
        for(int i=0;i<n;i++)mp[nums[i]].push_back(i);
        for(auto &c:mp){
            auto vc=c.second;
            int m=vc.size();
            for(int i=0;i<m;i++){
                int prev=(i==0?vc[i]+n-vc[m-1]:vc[i]-vc[i-1]);
                int next=(i==m-1?n-vc[m-1]+vc[0]:vc[i+1]-vc[i]);
                minDist[vc[i]]=min(prev,next);
            }
            if(m==1)minDist[vc[0]]=-1;
        }

        vector<int>ans;
        for(auto &c:queries)ans.push_back(minDist[c]);
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(Q) => O(N);
// Space Complexity: O(N) + O(N) + O(Q) => O(N);
// Q = queries.size();