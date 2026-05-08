// Problem Link: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/?envType=daily-question&envId=2026-05-08

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();

        int mx=1e6+1;
        static vector<vector<int>> factors(mx);
        if(factors[2].empty()){
            for(int i=2;i<mx;i++){
                if(factors[i].empty()){
                    for(int j=i;j<mx;j+=i) factors[j].push_back(i);
                }
            }
        }

        unordered_map<int,vector<int>> edges;
        for(int i=0;i<n;i++){
            for(auto &p:factors[nums[i]]) edges[p].push_back(i);
        }

        int ans=0;
        vector<int> vis(n,0);
        vis[0]=1;

        vector<int> q={0};
        while(true){
            vector<int> q2;

            for(auto &i:q){
                if(i==n-1) return ans;

                if(i>0 && vis[i-1]==0){
                    vis[i-1]=1;
                    q2.push_back(i-1);
                }
                if(i<n-1 && vis[i+1]==0){
                    vis[i+1]=1;
                    q2.push_back(i+1);
                }
                if(factors[nums[i]].size()==1){
                    int p=nums[i];
                    if(edges.count(p)){
                        for(auto &j:edges[p]){
                            if(vis[j]==0){
                                vis[j]=1;
                                q2.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }
            q=move(q2);
            ans++;
        }
        return ans;
    }
};

// Time Complexity : O(Mlog(logM)) + O(N*K) + O(N+K) => O(Mlog(logM) + N);
// Space Complexity: O(M*K) + O(N*K) + O(N) => O(M + N);
// K is the unique prime factor and K <= 7 for 1e6+1 && M <= 1e6+1;