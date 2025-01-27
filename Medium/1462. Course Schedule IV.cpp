// Problem Link: https://leetcode.com/problems/course-schedule-iv/description/

class Solution {
public:
    map<int,set<int>>mp;
    set<int> dfs(int u,auto &adj){
        if(mp.count(u))return mp[u];
        mp[u].insert(u);
        for(auto &c:adj[u]){
            auto curr=dfs(c,adj);
            mp[u].insert(curr.begin(),curr.end());
        }
        return mp[u];
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for(auto &c:prerequisites){
            adj[c[1]].push_back(c[0]);
        }

        for(int i=0;i<numCourses;i++){
            dfs(i,adj);
        }
        vector<bool>ans;
        for(auto &c:queries){
            ans.push_back(mp[c[1]].find(c[0])!=mp[c[1]].end());
        }
        return ans;
    }
};

// Time Complexity : O(N^2) + O(Q*logN) => O(N^2);
// Space Complexity: O(N^2) + O(Q) => O(N^2);
// Q is number of queries here;