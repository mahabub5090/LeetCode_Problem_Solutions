// Problem Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> compo(n,0);
        int compoCnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) compoCnt++;
            compo[i]=compoCnt;
        }

        vector<int> ans;
        for(auto &c:queries) ans.push_back(compo[c[0]]==compo[c[1]]);
        return vector<bool>(ans.begin(),ans.end());
    }
};

// Time Complexity : O(N) + O(Q) => O(N+Q) => O(N);
// Space Complexity: O(N) + O(Q) => O(N+Q) => O(N);
// Q = queries.size(), 1 <= N, Q <=1e5;