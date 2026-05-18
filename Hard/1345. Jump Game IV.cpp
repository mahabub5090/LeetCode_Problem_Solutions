// Problem Link: https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);

        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0]=1;

        while(q.size()){
            auto [i,cnt]=q.front(); q.pop();

            if(i==n-1) return cnt;
            vis[i]=1;

            for(auto &c:mp[arr[i]]){
                if(c!=i && vis[c]==0) q.push({c,cnt+1});
            }
            mp.erase(arr[i]);

            if(i-1>=0 && vis[i-1]==0) q.push({i-1,cnt+1});
            if(i+1<n && vis[i+1]==0) q.push({i+1,cnt+1});
        }
        return 0;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N) + O(N) + O(N) => O(N);